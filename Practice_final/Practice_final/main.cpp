#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
#include "TreeNode.h"

using namespace std;

void search_helper(TreeNode *root, bool &check, int value)
{
	if (root == nullptr)
	{
		return;
	}
	if(root->value == value)
	{
		check = true;
	}
	search_helper(root->left, check, value);
	search_helper(root->right, check, value);
}

bool searchTree(TreeNode *root, int value)
{
	bool check = false;
	search_helper(root, check, value);

    return check;
}


void vector_helper( TreeNode *root, vector<int> &numbers, int &i)
{
	if(root == nullptr)
	{
		return;
	}
	vector_helper(root->left, numbers, i);
	numbers.resize(numbers.size() + 1);
	numbers[i] = root->value;
	i = i + 1;
	vector_helper(root->right, numbers, i);

}

vector<int> bstToVector(TreeNode *root)
{
	int i = 0;
    vector<int> numbers{1};
	vector_helper(root, numbers,i);
    return numbers;
}

bool isHeap(vector<int> &numbers)
{
	for (int x = 0;x < (numbers.size() / 2 - 1);x++)
	{
		if((numbers[x] > numbers[(x * 2 ) + 1]) || (numbers[x] > numbers[(x * 2) + 2]))
		{
			return false;
		}

	}
    return true;
}

vector<int> mergeSorted(vector<int> left, vector<int> right)
{
    vector<int> result{};

	while (left.empty() == false || right.empty() == false)
	{
		if (left.empty() == true || right.empty() == true)
		{
			if (left.empty() == true)
			{
				result.push_back(right.front());
				right.erase(right.begin());

			}
			else
			{
				result.push_back(left.front());
				left.erase(left.begin());

			}

		}
		else {
			result.resize(result.size() + 1);
			if (left.front() < right.front())
			{
				result.push_back(left.front());
				left.erase(left.begin());
			}
			else
			{
				result.push_back(right.front());
				right.erase(right.begin());
			}
		}
	}
    return result;
}

int findNthSmallest(vector<int> numbers, int n)
{
    return numbers[0];
}

char findMostCommon(string text)
{
    return text[0];
}

int main()
{
    string test_text = "ababbcbccc";
    vector<int> vector_heap{1, 2, 3, 4, 5, 6, 7, 8, 9, 20};
    vector<int> sorted = {3, 4, 9, 12, 15, 17};
    vector<int> numbers{5, 2, 1, 9, 3, 7, 4};
    vector<int> heap{1, 3, 2, 9, 7, 5, 4};
    TreeNode *root = new TreeNode{10};
    root->left = new TreeNode{5};
    root->left->left = new TreeNode{1};
    root->left->right = new TreeNode{7};
    root->left->right->left = new TreeNode{6};
    root->right = new TreeNode{20};
    root->right->right = new TreeNode{50};
    root->right->left = new TreeNode{15};

    cout << "Searching tree for 15: " << searchTree(root, 15) << " (expected: 1)" << endl;
    cout << "Searching tree for 0: " << searchTree(root, 0) << " (expected: 0)" << endl;
    cout << "Converting tree to vector: ";
    vector<int> treeAsVector = bstToVector(root);
	cout << endl << " Given   : ";
	treeAsVector.resize(treeAsVector.size() - 1);
    for(auto i : treeAsVector)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << " Expected: 1 5 6 7 10 15 20 50";
    cout << endl << endl;
    cout << "Is vector heap: " << isHeap(vector_heap) << " (expected: 1)" << endl;
    cout << "Is vector heap: " << isHeap(numbers) << " (expected: 0)" << endl;
    cout << "Is vector heap: " << isHeap(heap) << " (expected: 1)" << endl;
    cout << "Merging sorted vectors: ";
    vector<int> merged = mergeSorted(vector_heap, sorted);
    for(auto i : merged)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << " Expected: 1 2 3 3 4 4 5 6 7 8 9 9 12 15 17 20";
    cout << endl << endl;
    cout << "3rd smallest number: " << findNthSmallest(sorted, 3) << " (expected: 9)" << endl;
    cout << "Most common char: " << findMostCommon(test_text) << " (expected: 'c')" << endl;
    return 0;
}
