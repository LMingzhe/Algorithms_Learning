#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

/// @brief 注意相邻节点ID，需要用 unsigned int or long long 表示，避免溢出

// 节点类
class Node
{
private:
    unsigned int nodeID;
    vector<int> vlanID;
public:
    Node() = delete;
    Node(const unsigned int& nodeID) : nodeID(nodeID) {}

    vector<int> getVlanID() { return vlanID; }

    unsigned int getNodeID() { return nodeID; }

    void addVlanID(const int& vId)
    {
        vlanID.push_back(vId);
    }
};

// 判断两个节点是否连通
bool isConnected(const vector<int>& vlanID_A, const vector<int>& vlanID_B)
{
    for (int i = 0; i < vlanID_A.size(); i++)
    {
        for (int j = 0; j < vlanID_B.size(); j++)
        {
            if (vlanID_A[i] == vlanID_B[j])
            {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int m;
    vector<Node> neighborNodeSet;
    cin >> m;
    // cout << "输入m: " << " " << m << endl;
    Node A = Node(0);
    for (int i = 0; i < m; i++)
    {
        int vID;
        cin >> vID;
        A.addVlanID(vID);
    }

    int N;
    cin >> N;
    cin.ignore(); // 清除输入缓冲区中的换行符，确保下一个 std::getline 函数从新的一行开始读取数据。
    // cout << "输入N: " << " " << N << endl;
    if (N == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < N; i++)
    {
        // cout << "当前i: " << i << endl;
        string line;
        getline(std::cin, line);
        istringstream iss(line);
        unsigned int nodeID;
        iss >> nodeID;
        // cout << "Node ID: " << nodeID << endl;
        Node B = Node(nodeID);
        int portNum;
        iss >> portNum;
        int vID;
        while (iss >> vID)
        {
            // cout << "vlan ID: " << vID << endl;
            B.addVlanID(vID);
        }
        neighborNodeSet.push_back(B);
    }
    
    int connNum = 0;
    vector<unsigned int> connNodeID;
    for (int i = 0; i < neighborNodeSet.size(); i++)
    {
        if (isConnected(A.getVlanID(), neighborNodeSet[i].getVlanID()))
        {
            // cout << "A connect with " << neighborNodeSet[i].getNodeID() << endl;
            connNum++;
            connNodeID.push_back(neighborNodeSet[i].getNodeID());
        }
    }
    sort(connNodeID.begin(), connNodeID.end());
    cout << connNum << endl;
    for (int i = 0; i < connNodeID.size(); i++)
    {
        if (i == connNodeID.size() - 1)
        {
            cout << connNodeID[i] << endl;
        } else {
            cout << connNodeID[i] << " ";
        }
    }
    return 0;
}