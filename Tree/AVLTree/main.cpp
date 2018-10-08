//created by insane-abhi
//driver function
//sample code for testing AVL
#include <iostream>
#include "AVL.cpp"

using namespace std;
int main() {
    int roll_no;
    string name;
    AVL<int, string> students;   //int represents key datatype and string represents value datatype
    cout << "Enter no. of entries: ";
    int n;
    cin >> n;
    cout << endl;
    for(int i=1; i<=n; i++) {
        cout << "Enter roll no: ";
        cin >> roll_no;
        cout << endl;
        cout << "Enter name: ";
        cin >> name;
        cout << endl;
        students.put(roll_no,name);
    }
    cout << "Search for a roll_no | Enter the roll.no: ";
    cin >> roll_no;
    cout << endl;
    cout << students.has(roll_no) << " (1 if present else 0)" << endl;
    cout << "Find name associated with a rollNo | Enter roll_no: ";
    cin >> roll_no;
    cout << students.get(roll_no) << endl;
    cout << "Remove a particular roll no. | Enter Roll no: ";
    cin >> roll_no;
    students.remove(roll_no);
    cout << "Printing the directory: " << endl;
    students.print_in_order();
    cout << "Printing Max and Min roll No. " << endl;
    cout << "Max: " << students.maximum() << " Min: " << students.minimum() << endl << "Enter no. for predecessor" << endl;
    cin >> roll_no;
    cout << students.predecessor(roll_no) << endl;
    cout << "Height of Tree: " << students.getHeight() << endl;
    cout << "No. Of Nodes: " << students.size() << endl;
    return 0;
}