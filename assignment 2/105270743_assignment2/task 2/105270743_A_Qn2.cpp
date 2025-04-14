#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

enum Genre 
{
    RAP = 0,
    POP = 1,
    KRNB = 2
};

struct Album
{
    string artistName;
    string albumName;
    Genre genre;
    int numberOfTracks;
    string tracks[3];           
    string trackFilePaths[3];    
};

// takes a genre and turns it into a string and converts it into its enum value
Genre getGenreFromString(string &genreStr) 
{
    if (genreStr == "POP") return POP;
    if (genreStr == "KRNB") return KRNB;
    if (genreStr == "RAP") return RAP;
}

// reads the album data from the function
int readAlbum(Album albums[])
{   
    string filePath; 
    cout << "Enter a file path to an Album: ";
    cin >> filePath; // enter the name of file (albums.txt)
    
    ifstream inFile(filePath); 
    
    if (inFile.fail()) 
    {
        cout << "Error opening file\n";
        exit(1);
    } 

    int i = 0;
    while(inFile >> albums[i].artistName >> albums[i].albumName)
    {
        string genreStr;
        inFile >> genreStr; 
        albums[i].genre = getGenreFromString(genreStr); 

        inFile >> albums[i].numberOfTracks;

        for (int j = 0; j < albums[i].numberOfTracks; j++) {
            inFile >> albums[i].tracks[j];         
            inFile >> albums[i].trackFilePaths[j]; 
        }
        
        i++;
    }

    inFile.close();
    return i; 
}

// displays the information for the artist and albums in the file
void displayAll(Album albums[], int albumCount)
{
    for(int i = 0; i < albumCount; i++)
    {
        cout << i + 1 << ": Title: " << albums[i].albumName 
        << " Artist: " << albums[i].artistName 
        << endl;
    }
}
 // makes it possible to update the names of the album
void updateAlbum(Album albums[], int albumCount)
{
    int albumChoice;
    for(int i = 0; i < albumCount; i++) 
    {
        cout << i + 1 << ": Title: " << albums[i].albumName 
        << " Artist: " << albums[i].artistName << endl;
    }

    cout << "Enter the Album to edit: ";
    cin >> albumChoice;

    if (albumChoice > 0 and albumChoice <= albumCount)
    {
        int albumIndex = albumChoice - 1; // because the data is stored in the array as 0, 1, 2 not 1, 2, 3
        int selection;
        cout << "Editing Album: " << albums[albumIndex].albumName << endl;

        cout << "What to edit: \n1.Title\n2.Genre\nEnter selection: ";
        cin >> selection;

        if (selection == 1)
        {
            cout << "Enter new album name: ";
            string newAlbumName;
            getline(cin, newAlbumName);

            if (!newAlbumName.empty()) 
            {
                albums[albumIndex].albumName = newAlbumName;
                cout << "Album name updated to: " << newAlbumName << endl;
            }
        }
        else if (selection == 2)
        {
            cout << "code not fully implemented :(( " << endl;
        }
    }
    else if (albumChoice == 0) {
        cout << "Returning to Main Menu..." << endl;
    } 
    else 
    {
        cout << "Invalid album choice!" << endl;
    }
}

// displays the second menu, to display the albums
void displayAlbumsMenu(Album albums[], int albumCount)
{
    int choice;
    do
    {
        cout << "\nDisplay Album Menu:" << endl;
        cout << "1. Display all Albums" << endl;
        cout << "2. Display Albums by Genre" << endl;
        cout << "3. Back to Main Menu" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                displayAll(albums, albumCount); 
                break;

            case 2: 
            {
                int genreChoice;
                cout << "1.POP\n2.KRnB\n3.RAP ";
                cout << "\nPick a genre: ";
                cin >> genreChoice;

                if(genreChoice == 1)
                {
                    cout <<"\nTitle: " << albums[0].albumName 
                    <<" Artist: " << albums[0].artistName 
                    <<" Genre: POP";
                }
                else if(genreChoice == 2)
                {
                    cout <<"\nTitle: " << albums[1].albumName 
                    <<" Artist: " << albums[1].artistName 
                    <<" Genre: KRnB";
                }
                else if(genreChoice == 3)
                {
                    cout <<"Title: " << albums[2].albumName 
                    <<" Artist: " << albums[2].artistName 
                    <<" Genre: RAP"
                    << endl;
                }
                break;
            }

            case 3:
                cout << "Returning to Main Menu..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);
}

// selecting an album to play
void albumSelection(Album albums[], int &albumCount)
{
    int choice;

  do
  {
    cout <<"\n1. Title: " << albums[0].albumName << " Artist: " << albums[0].artistName << " Genre: POP" << endl;
    cout <<"2. Title: " << albums[1].albumName << " Artist: " << albums[1].artistName << " Genre: KRnB" << endl;
    cout <<"3. Title: " << albums[2].albumName << " Artist: " << albums[2].artistName << " Genre: RAP" << endl;
    cout <<"4. Exit this page"<<endl;
    cout <<"Enter an Album number: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            int playingSong;

            cout <<"\nTitle: " << albums[0].albumName << " Artist: " << albums[0].artistName << " Genre: POP" << endl;
            cout<<"1. Trackname: " << albums[0].tracks[0] << endl;
            cout<<"2. Trackname: " << albums[0].tracks[1] << endl;
            cout<<"3. Trackname: " << albums[0].tracks[2] << endl;
            cout << "Select a tack to play: ";
            cin >> playingSong;

            if(playingSong == 1)
            {
                cout << "Playing track: " << albums[0].tracks[0] <<" from album " << albums[0].albumName << endl;
            }
            if(playingSong == 2)
            {
                cout << "Playing track: " << albums[0].tracks[1] <<" from album " << albums[0].albumName << endl;
            }
            if(playingSong == 3)
            {
                cout << "Playing track: " << albums[0].tracks[2] <<" from album " << albums[0].albumName << endl;
            }
            break;
        }
        
        case 2:
        {
            int playingSong;
            
            cout <<"\nTitle: " << albums[1].albumName << " Artist: " << albums[1].artistName << " Genre: KRnb" << endl;
            cout<<"1. Trackname: " << albums[1].tracks[0] << endl;
            cout<<"2. Trackname: " << albums[1].tracks[1] << endl;
            cout << "Select a tack to play: ";
            cin >> playingSong;

            if(playingSong == 1)
            {
                cout << "Playing track: " << albums[1].tracks[0] <<" from album " << albums[1].albumName << endl;
            }
            if(playingSong == 2)
            {
                cout << "Playing track: " << albums[1].tracks[1] <<" from album " << albums[1].albumName << endl;
            }
            break;
        }
        case 3:
        {
            int playingSong;
            
            cout <<"\nTitle: " << albums[2].albumName << " Artist: " << albums[2].artistName << " Genre: RAP" << endl;
            cout<<"1. Trackname: " << albums[2].tracks[0] << endl;
            cout << "Select a tack to play: ";
            cin >> playingSong;

            if(playingSong == 1)
            {
                cout << "Playing track: " << albums[2].tracks[0] <<" from album " << albums[2].albumName << endl;
            }
            break;
        }
        case 4:
            cout << "Exiting the application..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
    }
  } while(choice != 4);
  
}

// the main menu
void menu(Album albums[], int &albumCount)
{
    int choice;

    do
    {
        cout << "\nMain Menu:" << endl;
        cout << "1. Read in Albums" << endl;
        cout << "2. Display Albums" << endl;
        cout << "3. Select an Album to Play" << endl;
        cout << "4. Update an Existing Album" << endl;
        cout << "5. Exit the Application" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:  
            {
                albumCount = readAlbum(albums); 
                cout << albumCount << " albums read from file." << endl;
                break;
            }
            case 2:
                displayAlbumsMenu(albums, albumCount);
                break;
            case 3:
                albumSelection(albums, albumCount);
                break;
            case 4:
                updateAlbum(albums, albumCount);
                break;
            case 5:
                cout << "Exiting the application..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);
}

int main()
{
    Album albums[100]; // max amount of array to 100
    int albumCount = 0;

    menu(albums, albumCount); 
    
    return 0;
} 
