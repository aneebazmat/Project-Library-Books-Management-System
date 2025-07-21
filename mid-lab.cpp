#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
   int num;
   string id;
   string book_category;
   int days;
   double fine = 0;
   int count = 0;

   do{
    cout << "Hoe many students are borrowing books ? ";
    cin >> num;

    if ( num < 1)
    {
        cout << "Error.The number must be greater than 1"<<endl;
       // cin.clear();
        //cin.ignore(1000,'\n')
        cout << "Enter number of students again.";
        cin >> num;
    }
   }while( num < 1);

   cout << "Enter student details :" << endl;

   for (int i=1; i<=num; i++)
   {
       cout << "Enter Student id (or type 'exit' to stop) : ";
       cin >> id;

       if (id == "exit")
       {
           break;
       }
       cout << "Enter book category(fiction,science,history,technology) : ";
       cin >> book_category;
       cout << "Enter number of days book was kept : ";
       cin >> days;

       if (days == 14)
       {
           fine = 0;
       }
       else
       if (days > 14)
       {
            if(book_category == "fiction")
            {
                fine = ((days - 14) * 0.5 );
            }
            else 
            if (book_category == "science")
            {
                fine = ((days - 14) * 1.0 );
            }
            else 
            if (book_category == "history")
            {
                fine = ((days - 14) * 1.5 );
            }
            else 
            if(book_category == "technology")
            {
                fine = ((days - 14) * 2.0 );
            }
       }
       count++; 

       cout << "-------------------------------------------------" << endl;

        cout << "Student I'D : " << id << endl;
        cout << "Book Category : " << book_category << endl;
        cout << "Number of Days : " << days << endl;
        cout << "Fine : " << fine << endl;

        cout << "-------------------------------------------------" << endl;

        ofstream outFile ("records.txt");
   
        outFile << "Student I'D : " << id << endl;
        outFile << "Book Category : " << book_category << endl;
        outFile << "Number of Days : " << days << endl;
        outFile << "Fine : " << fine << endl;
        outFile << "Total Student Processed : " << count << endl;
     
        outFile.close();
   }

   cout << "Total Student Processed : " << count << endl;

//    ofstream outFile ("records.txt");
   
//    outFile << "Student I'D : " << id << endl;
//    outFile << "Book Category : " << book_category << endl;
//    outFile << "Number of Days : " << days << endl;
//    outFile << "Fine : " << fine << endl;
//    outFile << "Total Student Processed : " << count << endl;

//    outFile.close();

    return 0;
}