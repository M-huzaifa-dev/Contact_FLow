#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;
struct people
{
    string name, number;
};

int loaddata(people person[], int N)
{
    ifstream filei("phonebook.csv");
    string line;
    int count = 0;
    if (filei.is_open())
    {
        while (getline(filei, line) && count < N)
        {
            stringstream ss(line);
            getline(ss, person[count].name, ',');
            getline(ss, person[count].number);
            count++;
        }
        filei.close();
        cout << "Contacts loaded from file." << endl;
    }
    return count;
}

void sortcontacts(people person[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        int small_index = i;
        for (int j = i + 1; j < count; j++)
        {
            if (person[j].name < person[small_index].name)
            {
                small_index = j;
            }
        }
        if (small_index != i)
        {

            people temp = person[i];
            person[i] = person[small_index];
            person[small_index] = temp;
        }
    }
}

void search(people person[], int count)
{
    string target;
    cout << "Search for name: " << endl;
    getline(cin, target);

    for (int i = 0; i < target.length(); i++)
    {
        target[i] = tolower(target[i]);
    }
    int low = 0, high = count - 1;
    bool found = false;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        string tempName = person[mid].name;
        for (int i = 0; i < tempName.length(); i++)
        {
            tempName[i] = tolower(tempName[i]);
        }
        if (tempName == target)
        {
            cout << "Found Number: || " << person[mid].number << endl;
            found = true;
            break;
        }
        else if (tempName < target)
        {
            low = mid + 1;
        }
        else

        {
            high = mid - 1;
        }
    }
    if (!found)
    {
        cout << "Not Found." << endl;
    }
}

void saveContacts(people person[], int count)
{
    ofstream fileo("phonebook.csv");
    for (int i = 0; i < count; i++)
    {
        fileo << person[i].name << "," << person[i].number << "\n";
    }
    fileo.close();
    cout << "Data synced to file Successfully" << endl;
}
int main()
{

    const int MAX = 100;

    people person[MAX];
    int currCount = loaddata(person, MAX); 
    int choice;
    do
    {
        cout << "\n--- CONTACT MANAGER ---" << endl;
        cout << "1. Add New Contacts" << endl;
        cout << "2. Search Contact" << endl;
        cout << "3. Show All (Sorted)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            
            if (currCount < MAX)
            {
                cout << "Enter name: ";
                getline(cin, person[currCount].name);
                cout << "Enter number: ";
                getline(cin, person[currCount].number);
                currCount++;

                
                sortcontacts(person, currCount);
                
                cout << "Contact added!" << endl;
                saveContacts(person, currCount);
            }
            else
            {
                cout << "Memory Full!" << endl;
            }
            break;

        case 2:
            search(person, currCount);
            break;

        case 3:
            cout << "\n--- All Contacts ---" << endl;
            for (int i = 0; i < currCount; i++)
            {
                cout << i + 1 << ". " << person[i].name << " , " << person[i].number << endl;

            }
            break;

        case 4:
            cout << "Exiting!" << endl;
            break;

        default:
            cout << "Invalid choice!." << endl;
        }
    } while (choice != 4);

    return 0;

}
