/******

写了半天 只有50分。。。。

开始写完全没思路，大概看了一下别人满分题解，之后自己写还是g了

100分大佬代码：https://blog.csdn.net/zjx1230/article/details/114540874

******/

#include <bits/stdc++.h>
using namespace std;

struct file {
    bool is_dir = true;
    map<string, file*> m;
    file* parent;
    string name;
    long long ld=-1, lr=-1;
    long long rd, rr;
};

file* root = new file();

vector<string> split(string str, string seperator) {
    vector<string> result;
    result.push_back("/");
    if (str == "/") return result;
    int index = 1;
    int find_index = str.find(seperator, index);
    while(find_index != string::npos) {
        result.push_back(str.substr(index, find_index-index));
        index = find_index+1;
        find_index = str.find(seperator, index);
    }
    result.push_back(str.substr(index, str.size()-index));
    return result;
}

bool create_file(file* f, string fileName, long long size) {
    if (f->m[fileName] != nullptr) size -= f->m[fileName]->rd;
    if (f->rd + size > f->ld && f->ld != -1) return false;
    f->rd += size;
    file* tmp = f;
    vector<file*> fs;
    bool flag = true;
    while(tmp != nullptr) {
        tmp->rr += size;
        fs.push_back(tmp);
        if (tmp->rr > tmp->lr && tmp->lr != -1) {
            flag = false;
            break;
        }
        tmp = tmp->parent;
    }
    if (flag == true) {
        file* new_file = new file();
        new_file->is_dir = false;
        new_file->parent = f;
        new_file->name = fileName;
        new_file->rd = size;
        f->m[fileName] = new_file;
        return true;
    } else {
        f->rd -= size;
        for (int i=0; i<fs.size(); i++)
            fs[i]->rr -= size;
        return false;
    }
}

void create_node(file* f, string node_name) {
    file* new_node = new file();
    new_node->parent = f;
    new_node->name = node_name;
    f->m[node_name] = new_node;
    return;
}

int is_dir(file* f, vector<string> path, int deep, string file_name) {
    if (deep == path.size()-1) {
        if (f->m[path[deep]] == nullptr) return 0; // 创建文件
        else {
            file* tmp = f->m[path[deep]];
            if (tmp->is_dir == true) return 1; // 是目录
            else return 0; // 文件存在
        }
    }
    if (f->m[path[deep]] == nullptr) return 0;
    else if (f->m[path[deep]]->is_dir == false) return 1; // 路径上有文件
    else return is_dir(f->m[path[deep]], path, deep+1, file_name);
}


int delete_judge(file* f, vector<string> path, int deep, string file_name) {
    if (deep == path.size()-1) {
        if (f->m[path[deep]] == nullptr) return 0; // 路径不存在
        else {
            file* tmp = f->m[path[deep]];
            if (tmp->is_dir == true) return 1; // 是目录
            else return 2; // 是文件
        }
    }
    if (f->m[path[deep]] == nullptr) return 0; // 路径不存在
    else if (f->m[path[deep]]->is_dir == false) return 0; // 路径上有文件
    else return delete_judge(f->m[path[deep]], path, deep+1, file_name);
}

int update_judge(file* f, vector<string> path, int deep, string file_name) {
    if (path.size() == 1) return true;
    if (deep == path.size()-1) {
        if (f->m[path[deep]] == nullptr) return 0; // 路径不存在
        else {
            file* tmp = f->m[path[deep]];
            if (tmp->is_dir == true) return 1; // 是目录
            else return 2; // 是文件
        }
    }
    if (f->m[path[deep]] == nullptr) return 0; // 路径不存在
    else if (f->m[path[deep]]->is_dir == false) return 0; // 路径上有文件
    else return update_judge(f->m[path[deep]], path, deep+1, file_name);
}

bool operator_update(vector<string> path, long long ld, long long lr) {
    file* tmp = root;
    for (int i=1; i<path.size(); i++) {
        tmp = tmp->m[path[i]];
    }
    if (ld < tmp->rd && ld != 0) return false;
    if (lr < tmp->rr && lr != 0) return false;
    if (ld != 0) tmp->ld = ld;
    else tmp->ld = -1;
    if (lr != 0) tmp->lr = lr;
    else tmp->lr = -1;
    return true;
}

void operator_delete(vector<string> path) {
    vector<file*> p;
    file* tmp = root;
    p.push_back(tmp);
    for (int i=1; i<path.size()-1; i++) {
        tmp = tmp->m[path[i]];
        p.push_back(tmp);
    }
    tmp = tmp->m[path[path.size()-1]];
    p[p.size()-1]->m.erase(tmp->name);
    tmp->parent = nullptr;
    if (tmp->is_dir) {
        for (int i=0; i<p.size(); i++) {
            p[i]->rr -= tmp->rr;
        }
    } else {
        p[p.size()-1]->rd -= tmp->rd;
        for (int i=0; i<p.size(); i++) {
            p[i]->rr -= tmp->rd;
        }
    }
}


bool operator_create(file* f, vector<string> path, int deep, string file_name, long long size) {
    if (deep == path.size()-1) {
        return create_file(f, file_name, size);
    }
    if (f->m[path[deep]] == nullptr)
        create_node(f, path[deep]);
    return operator_create(f->m[path[deep]], path, deep+1, file_name, size);
}

int main() {
    int n;
    cin >> n;
    string type;
    root->name = "/";
    while(n--) {
        cin >> type;
        if (type == "C") {
            string path;
            long long size;
            cin >> path >> size;
            file* tmp_root = root;
            vector<string> p = split(path, "/");
            if (is_dir(tmp_root, p, 1, p[p.size()-1])) {
                cout << "N" << endl;
                continue;
            } else if (operator_create(tmp_root, p, 1, p[p.size()-1], size)) {
                cout << "Y" << endl;
            } else {
                cout << "N" << endl;
            }
        } else if (type == "R") {
            string path;
            cin >> path;
            vector<string> p = split(path, "/");
            if (delete_judge(root, p, 1, p[p.size()-1])) 
                operator_delete(p);
            cout << "Y" << endl;
        } else if (type == "Q") {
            string path;
            long long ld, lr;
            cin >> path >> ld >> lr;
            vector<string> p = split(path, "/");
            if (update_judge(root, p, 1, p[p.size()-1]) != true) {
                cout << "N" << endl;
            } else {
                if (operator_update(p, ld, lr)) {
                    cout << "Y" << endl;
                } else {
                    cout << "N" << endl;
                }
            }
        }
    }
    return 0;
}