# include <dirent.h>
# include <filesystem>
# include <fstream>
# include <iostream>
# include <string>
# include <cstdio>

using namespace std;


void ShowDir()
{
    DIR *d;
    struct dirent *dir;
    d = opendir(".");

    if(d)
    {

        while( (dir=readdir(d))!=NULL )
        {
            cout<<dir->d_name<<endl;
        }
    }
    else
    {
        cout<<"Unable to execute the command!!\n";
    }

}

void SearchFile()
{

    DIR *d;
    struct dirent *dir;

    string filename = "";

    cout<<"Enter File Name:\n";
    cin>>filename;

    d = opendir(".");

    if(d)
    {
        bool isFileFound = false;

        while( (dir=readdir(d)) != NULL )
        {
            if(strcmp(dir->d_name,filename.c_str()) == 0) /// 5 - 3
            {
                cout<<"File Found\n";
                isFileFound = true;
            }
        }
        if(!isFileFound) {
            cout << "File not found\n";
        }

    }
    else
    {
        cout<<"Unable to execute the command!!\n";
    }

}

void DelFile()
{

   char fileName[100];;
   cout<<"Enter File Name:\n";
   cin>>fileName;

    cout << "Deleting file " << fileName << endl;

    int result = remove(fileName);

    if (result == 0)
    {
        cout << "File is deleted\n"
             << endl;
    }
    else
    {
        cout << "Unable to delete.\n"
             << endl;
    }
}


int main()
{
    freopen("in.text", "r", stdin);

    int option;
    cout<<"Press 1 for Show Directory\n";
    cout<<"Press 2 for Show Search a file\n";
    cout<<"Press 3 for Show Delete a file\n";

    cin>>option;

    if(option == 1) {
        ShowDir();
    }
    else if(option == 2) {
        SearchFile();
    }
    else if(option == 3) {
        DelFile();
    }
    else {
        cout<<"You have choose Wrong option\n";
    }

    return 0;
}