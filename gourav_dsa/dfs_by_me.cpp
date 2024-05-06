#include <bits/stdc++.h>
using namespace std;

int main()
{
    int edges, vertices;
    cout << "Input no. of edges and vertices" << endl;
    cin >> edges >> vertices;
    int tree[edges][2];
    vector<int> dfs_traversal;
    cout << "enter edges" << endl;
    vector<int> parent_vec;
    for (int i = 0; i < edges; i++)
    {
        int e1, e2;
        cout << "enter edges" << endl;
        cin >> e1 >> e2;
        tree[i][0] = e1;
        tree[i][1] = e2;
    }
    parent_vec.push_back(tree[0][0]);
    int checker = tree[0][0];
    int stop = 0;
    int counter = 0;
    while (true)
    {
        cout << "loop timer" << endl;
        int parent = 0;
        for (int i = 0; i < edges; i++)
        {
            if (checker == tree[i][0])
            {

                dfs_traversal.push_back(tree[i][0]);
                counter += 2;
                checker = tree[i][1];
                parent_vec.push_back(tree[i][1]);
                tree[i][0] = 1000;
                tree[i][1] = 1000;
                parent = 1;
            }

            else if (checker == tree[i][1])
            {

                dfs_traversal.push_back(tree[i][1]);
                counter += 2;
                checker = tree[i][0];
                parent_vec.push_back(tree[i][0]);
                tree[i][1] = 1000;
                tree[i][0] = 1000;
                parent = 1;
            }
        }
        

        if (counter == edges * 2 && parent == 0)
        {
            break;
        }
    }
    for (int i = 0; i < dfs_traversal.size(); i++)
    {
        cout << dfs_traversal[i];
    }
}