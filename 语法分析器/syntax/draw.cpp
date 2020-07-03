#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;
struct Node
{
    string val;
    vector<Node *> children;
    int id_index;
    Node() {}
    Node(string info) { val = info; }
    Node(string info, vector<Node *> sons)
    {
        val = info;
        for (auto x : sons)
        {
            children.push_back(x);
        }
    }
};

//stack<string>lexical;
stack<Node *> syntax;
Node *root;
int node_name_in_gv = 0;

int judge(string line);
void read_file(string file_name);
//void handle(string sentance);
vector<string> parse(string line);
void reduce(vector<string> words);
void traversal(Node *dot);
void print_output(string file_out);
void traversal_twice(Node *dot);

int main(int argc, const char **argv)
{
    string file_name = "helperOutput.txt";
    read_file(file_name);
    //traversal(root);
    string file_out = "ASTvis.gv";
    print_output(file_out);
    return 0;
}

void read_file(string file_name)
{
    fstream fin;
    fin.open(file_name);
    assert(fin.is_open());

    string line;
    while (!fin.eof())
    {
        getline(fin, line);
        if (line.find("->") != -1)
        {
            //cout<<line<<endl;
            vector<string> a = parse(line);
            reduce(a);
            if (a[0] == "Program")
                root = syntax.top();
        }
        else
        {
            syntax.push(new Node(line));
        }
    }

    fin.close();
}

void reduce(vector<string> words)
{
    Node *parent = new Node(words[0]);
    for (int i = 2; i < words.size(); i++)
    {
        parent->children.push_back(syntax.top());
        syntax.pop();
    }
    //逆转
    reverse(parent->children.begin(), parent->children.end());

    syntax.push(parent);
}
vector<string> parse(string line)
{
    stringstream is(line);
    vector<string> ans;
    string tmp;
    while (is >> tmp)
    {
        ans.push_back(tmp);
    }
    return ans;
}

void traversal(Node *dot)
{
    if (!dot)
        return;
    node_name_in_gv++;
    dot->id_index = node_name_in_gv;
    if (dot->val[0] == '\"')
    { //防止"this is a string"画图是"产生冲突
        string tmpp = "\\" + dot->val;
        tmpp[tmpp.size() - 1] = '\\';
        tmpp += "\"";
        dot->val = tmpp;
    }
    if (dot->children.size() > 0) //不是子结点
    {
        cout << "    " << node_name_in_gv << "[label=\"" << dot->val << "\"];" << endl;
    }
    else
    {
        cout << "    " << node_name_in_gv << "[label=\"" << dot->val << "\",peripheries=2, style=filled, color=\"#eecc80\"];" << endl;
    }

    for (int i = 0; i < dot->children.size(); i++)
    {
        traversal(dot->children[i]);
    }
}

void traversal_twice(Node *dot)
{
    if (!dot)
        return;
    for (int i = 0; i < dot->children.size(); i++)
    {
        cout << "    " << dot->id_index << " -> " << dot->children[i]->id_index << " ;" << endl;
        traversal_twice(dot->children[i]);
    }
    delete dot;
}

void print_output(string file_out)
{
    //打开输出文件
    ofstream outf(file_out);

    //获取cout默认输出
    streambuf *default_buf = cout.rdbuf();

    //重定向cout输出到文件
    cout.rdbuf(outf.rdbuf());

    cout << "digraph graphname {" << endl;
    traversal(root);
    node_name_in_gv = 0;
    traversal_twice(root);
    cout << "}" << endl;

    //恢复cout默认输出
    cout.rdbuf(default_buf);
}