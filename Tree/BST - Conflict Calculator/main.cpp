#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
class Node
{
//=================================================================================================
    public:
        Node(int start, int mid, int end, Node* left = nullptr, Node* right = nullptr)
            : m_start(start), m_mid(mid), m_end(end), m_left(left), m_right(right) {}
//=================================================================================================
    public:
        int m_start, m_mid, m_end;
        Node *m_left;
        Node *m_right;
//=================================================================================================
};
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
class Tree
{
//=================================================================================================
    public:
//=================================================================================================
        Tree() : m_root(nullptr), m_nodeCount(0) {}
        ~Tree(){}
//=================================================================================================
        Node *&getsetRoot() {return m_root;}
        Node *getRoot() {return m_root;}
//=================================================================================================
        Node* find(Node* iter, int key)
        {
            if(iter == nullptr)
                return nullptr;
            else
            {
                if(key < iter->m_start)
                    return find(iter->m_left, key);
                else if(key > iter->m_start)
                    return find(iter->m_right, key);
                else
                    return iter;
            }
        }
//=================================================================================================
        Node* insert(Node* iter, int start, int mid, int end)
        {
            if(iter == nullptr)
                iter = new Node(start, mid, end);
            else
            {
                if(start < iter->m_start)
                    iter->m_left = insert(iter->m_left, start, mid, end);
                else
                    iter->m_right = insert(iter->m_right, start, mid, end);
            }
            return iter;
        }
//=================================================================================================
        Node* remove(Node *iter, int key)
        {
            if(iter == nullptr)
                return nullptr;
            else
            {
                if(key < iter->m_start)
                    iter->m_left = remove(iter->m_left, key);
                else if(key > iter->m_start)
                    iter->m_right = remove(iter->m_right, key);
                else
                {
                    if(iter->m_left == nullptr && iter->m_right == nullptr)
                    {
                        delete iter;
                        return nullptr;
                    }
                    else if ( (iter->m_left == nullptr && iter->m_right != nullptr) ||
                              (iter->m_left != nullptr && iter->m_right == nullptr) )
                    {
                        Node *temp;
                        if(iter->m_left != nullptr)
                            temp = iter->m_left;
                        else
                            temp = iter->m_right;

                        delete iter;
                        iter = temp;
                        return iter;
                    }
                    else
                    {
                        Node* min = getMin(iter->m_right);
                        iter->m_start = min->m_start;
                        iter->m_right = remove(iter->m_right, iter->m_start);
                        return iter;
                    }
                }
            }
        }
//=================================================================================================
        Node* getMin(Node *iter)
        {
            if(iter == nullptr)
                return nullptr;
            if(iter->m_left == nullptr)
                return iter;
            else
                return getMin(iter->m_left);
        }
//=================================================================================================
        Node* getMax(Node *iter)
        {
            if(iter == nullptr)
                return nullptr;
            if(iter->m_right == nullptr)
                return iter;
            else
                return getMax(iter->m_right);
        }
//=================================================================================================
        void print_inOrder(Node *iter, std::ofstream &writeToFile)
        {
            if(iter == nullptr)
                return;
            else
            {
                print_inOrder(iter->m_left, writeToFile);
                std::cout << iter->m_start << " " << iter->m_mid << " " << iter->m_end << "\n";
                writeToFile << iter->m_start << " " << iter->m_mid << " " << iter->m_end << "\n";
                print_inOrder(iter->m_right, writeToFile);
            }
        }
//=================================================================================================
        void print_preOrder(Node *iter)
        {
            if(iter == nullptr)
                return;
            else
            {
                std::cout << iter->m_start << " " << iter->m_mid << " " << iter->m_end << "\n";
                print_preOrder(iter->m_left);
                print_preOrder(iter->m_right);
            }
        }
//=================================================================================================
        void print_postOrder(Node *iter)
        {
            if(iter == nullptr)
                return;
            else
            {
                print_postOrder(iter->m_left);
                print_postOrder(iter->m_right);
                std::cout << iter->m_start << " " << iter->m_mid << " " << iter->m_end << "\n";
            }
        }
//=================================================================================================
    private:
//=================================================================================================
        Node *m_root;
        int m_nodeCount;
//=================================================================================================
};
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
struct Interval
{
    int start, mid, end;
    Interval(int a, int b, int c) : start(a), mid(b), end(c){}
    void display(){std::cout << start << " " << mid << " " << end << " " << getSum() << "\n";}
    int getSum(){return start+mid+end;}
    bool operator == (const Interval &obj){return (start==obj.start && mid==obj.mid && end==obj.end);}
};
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
void merge(std::vector<Interval> &arr, int left, int middle, int right);

void mergeSort(std::vector<Interval> &arr, int left, int right)
{
    if(left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}
void merge(std::vector<Interval> &arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<Interval> L, R;
    L.reserve(n1);
    R.reserve(n2);

    for(int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for(int i = 0; i < n2; ++i)
        R[i] = arr[middle + i + 1];

    int i = 0;
    int j = 0;
    int k = left;
    while(i < n1 && j < n2)
    {
        if(L[i].start <= R[j].start)
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while(j < n2)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    std::string fileName = "manager1.txt";
    const int totalFiles = 5;
    const int fileNameIndex = 7;

    //tree for compatible and conflicting intervals
    Tree compatible;
    Node *&root1 = compatible.getsetRoot();
    Tree conflict;
    Node *&root2 = conflict.getsetRoot();

    //vectors to push back data
    std::vector<Interval> compatibleVec;
    std::vector<Interval> conflictVec;

    //temporary interval which is the first time of the first read file
    Interval minimum(0, 0, 0);

    //randomize which file to read first
    srand(time(0));
    int randomNumber = rand() % totalFiles + 1;
	std::cout << "File Opened first: " << "Manager" << randomNumber << ".txt\n";

	//read data from all 5 files
    int iterNumber = 1;
    while(iterNumber <= totalFiles)
    {
        std::ifstream inf(fileName);
        if(!inf)
        {
            std::cout << "Cannot Open file " << fileName << std::endl;
            exit(1);
        }
        //goto the next file
        ++fileName[fileNameIndex];

        int size = 0;
        inf >> size;

        //read data from the file
        int start, mid, end;
        for(int i = 0; i < size; ++i)
        {
            inf >> start >> mid >> end;
            compatibleVec.push_back(Interval(start, mid, end));

            //set minimum to first data of the first read file
            if(randomNumber == iterNumber && i == 0)
                minimum = Interval(start, mid, end);
        }
        ++iterNumber;
    }

    //sort vector for comparison with previous interval
    mergeSort(compatibleVec, 0, compatibleVec.size());
    Interval previous(0, 0, 0);

    //for all elements in vector
    for(int i = 0; i < compatibleVec.size(); ++i)
    {
        //if intervals do not overlap then set previous to current
        if(previous.getSum() <= compatibleVec[i].start)
            previous = compatibleVec[i];
        //if overlaping
        else
        {
            //if minimum is current, remove previous overlapping interval, not current
            if(compatibleVec[i] == minimum)
            {
                conflictVec.push_back(compatibleVec[i - 1]);
                compatibleVec.erase(compatibleVec.begin() + i - 1);
                previous = minimum;
                --i;
            }
            //else remove current overlapping interval
            else
            {
                conflictVec.push_back(compatibleVec[i]);
                compatibleVec.erase(compatibleVec.begin() + i);
                --i;
            }
        }
    }

    //insert the element in the tress
    for(int i = 0; i < compatibleVec.size(); ++i)
        root1 = compatible.insert(root1, compatibleVec[i].start, compatibleVec[i].mid, compatibleVec[i].end);
    for(int i = 0; i < conflictVec.size(); ++i)
        root2 = conflict.insert(root2, conflictVec[i].start, conflictVec[i].mid, conflictVec[i].end);

    //display compatible and write to file
    std::ofstream compatibleFile("Compatible.txt");
    std::cout << "\nCompatible:" << std::endl;
        compatible.print_inOrder(root1, compatibleFile);

    //display conflicting and write to file
    std::ofstream conflictFile("Conflict.txt");
    std::cout << "\nConflict:" << std::endl;
        conflict.print_inOrder(root2, conflictFile);

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
