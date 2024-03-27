// File: CS112_A3_Part1_Section11,12_20231167_20231039_20231200.cpp
// Purpose: The program do a variety of filters on images.
// Author: Gamal Megahed Sayed Mohamed (20231039) (eng.gamalmegahed@gmail.com), Section 12 , Did Filter_1 , Filter_4 , Filter_7.
//         Mostafa Ehab Mostafa Akl (20231167) (mostafaehabakl@gmail.com) , Section 12 , Did Filter_2 , Filter_5 , Filter_8.
//         Walid Adel Mordy Rohyem (20231200) (khattabadel112005@gmail.com), Section 11 , Did Filter_3 . Filter_6.
//=================================================================================================================================
#include <bits/stdc++.h>
#include "Image_Class.h"
using namespace std;
string SYSTEM_COLOR;
string RESET_COLOR = "\033[0m";
string BOLD = "\033[1;37m";
string RED = "\033[1;31m";
string BLUE = "\033[1;34m";
string YELLOW = "\033[1;33m";
string WHITE = "\033[1;37m";
string GREEN = "\033[1;32m";
string CYAN = "\033[1;36m";
string PURPLE = "\033[1;35m";

int Invert_Image(){
    while (true){
        string filename,SYSTEM_COLOR,RESET_COLOR;
        cout << SYSTEM_COLOR << "Please,enter the name of the image you want to invert with (.png, .jpeg, .jpg, .bmp): " << RESET_COLOR;
        cin >> filename;
        Image khattab_image(filename);
        while(true){
            try {
                khattab_image.loadNewImage(filename);
                break;
            } catch( invalid_argument) {
                cout << "Please enter a valid photo \n" << endl;
                cin>>filename;
            }
        }

        for (int i = 0  ; i < khattab_image.width ; i++){
            for (int j = 0 ; j < khattab_image.height ; j++){
                unsigned int avg = 0;
                for (int k = 0 ; k < 3 ; k++){
                    khattab_image(i , j , k)=255- khattab_image(i,j,k);

                }
            }
        }
        cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;
        cin >> filename;
        khattab_image.saveImage(filename);
        cout<<SYSTEM_COLOR<<"Done Succefully!"<<RESET_COLOR<<endl;
        int choice;
        cout<<SYSTEM_COLOR<<"Do you want to restart again\n1)YES\n2)NO: "<<RESET_COLOR;
        cin>>choice;
        while (cin.fail()||(choice!=1 && choice!=2) ){
            cout<<SYSTEM_COLOR<<"Invalid input! Plaese, Follow the instructions."<<RESET_COLOR<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<SYSTEM_COLOR<<"Do you want to restart again\n1)YES\n2)NO: "<<RESET_COLOR;
            cin>>choice;
        }
        if (choice==2)break;}

    return 0;}
//====================================================================================================================
int Rotate_Image(){
    while (true){
        string filename,SYSTEM_COLOR,RESET_COLOR;
        cout << SYSTEM_COLOR << "Please,enter the name of the image you want to rotate with (.png, .jpeg, .jpg, .bmp): " << RESET_COLOR;
        cin >> filename;
        Image khattab_image(filename);
        while(true){
            try {
                khattab_image.loadNewImage(filename);
                break;
            } catch( invalid_argument) {
                cout << "Please enter a valid photo \n" << endl;
                cin>>filename;
            }
        }

        int angle;
        cout<<SYSTEM_COLOR<<"Enter the Angle ( 90 , 180 , 270 ,360): "<<RESET_COLOR;
        cin>>angle;
        while (cin.fail()||(angle!=90 && angle !=180 && angle!=270 && angle!=360) ){
            cout<<SYSTEM_COLOR<<"Invalid input! Plaese, Follow the instructions."<<RESET_COLOR<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<SYSTEM_COLOR<<"Enter the Angle ( 90 , 180 , 270 , 360 ): "<<RESET_COLOR;
            cin>>angle;
        }
        if (angle == 90){

            Image khattab_image2(khattab_image.height,khattab_image.width);
            for (int i = 0 ; i < khattab_image.width ; i++){
                for (int j = 0 ; j < khattab_image.height ; j++){
                    for (int k = 0 ; k < 3 ; k++){
                        khattab_image2(khattab_image.height-j-1,i,k)=khattab_image( i , j , k );
                    }
                }
            }
            cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;
            cin >> filename;
            khattab_image2.saveImage(filename);
            cout<<SYSTEM_COLOR<<"Done Succefully!"<<RESET_COLOR<<endl;
        }
        else if (angle==180){
            // Load the original image
            Image khattab_image2(khattab_image.width, khattab_image.height); // Create a new image with the same dimensions

            // Iterate over the original image pixels and copy them to the rotated image with adjusted coordinates
            for (int i = 0; i < khattab_image.width; i++) {
                for (int j = 0; j < khattab_image.height; j++) {
                    for (int k = 0; k < 3; k++) {
                        // Copy pixel from original image to rotated image with adjusted coordinates for 180-degree rotation
                        khattab_image2(khattab_image.width - i - 1, khattab_image.height - j - 1, k) = khattab_image(i, j, k);
                    }
                }
            }

            cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;
            cin >> filename;
            khattab_image2.saveImage(filename);
            cout<<SYSTEM_COLOR<<"Done Succefully!"<<RESET_COLOR<<endl;
        }
        else if (angle == 270){ // Load the original image
            Image khattab_image2(khattab_image.height, khattab_image.width); // Create a new image with swapped dimensions

            // Iterate over the original image pixels and copy them to the rotated image with swapped coordinates
            for (int i = 0; i < khattab_image.width; i++) {
                for (int j = 0; j < khattab_image.height; j++) {
                    for (int k = 0; k < 3; k++) {
                        // Copy pixel from original image to rotated image with swapped coordinates
                        khattab_image2(j, khattab_image.width - i - 1, k) = khattab_image(i, j, k);
                    }
                }
            }
            cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;
            cin >> filename;
            khattab_image2.saveImage(filename);
            cout<<SYSTEM_COLOR<<"Done Succefully!"<<RESET_COLOR<<endl;}
        else if ( angle == 360){
            Image khattab_image2(khattab_image.width,khattab_image.height);
            for (int i = 0 ; i < khattab_image.width ; i++){
                for (int j = 0 ; j < khattab_image.height ; j++){
                    for (int k = 0 ; k < 3 ; k++){
                        khattab_image2(i,j,k)=khattab_image( i , j , k );
                    }
                }
            }
            cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;
            cin >> filename;
            khattab_image2.saveImage(filename);
            cout<<SYSTEM_COLOR<<"Done Succefully!"<<RESET_COLOR<<endl;
        }
        int choice;
        cout<<SYSTEM_COLOR<<"Do you want to restart again\n1)YES\n2)NO: "<<RESET_COLOR;
        cin>>choice;
        while (cin.fail()||(choice!=1 && choice!=2) ){
            cout<<SYSTEM_COLOR<<"Invalid input! Plaese, Follow the instructions."<<RESET_COLOR<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<SYSTEM_COLOR<<"Do you want to restart again\n1)YES\n2)NO: "<<RESET_COLOR;
            cin>>choice;
        }
        if (choice==2)break;}

    return 0;

}

int get_int(const string&);
string color();
Image gray_scale();
Image Merge_Images();
Image Darken_and_Lighten_Image();
int Black_and_White();
int Flip_Image();
int Crop_Images();

int main()
{
    int choice;
    cout << BOLD << "🤩🥰❤ Ahllan Ya User Ya Habyby ❤🥰🤩\n"
         << RESET_COLOR;
    SYSTEM_COLOR = color();
    cout << "\n============\n";
    while (true)
    {
        cout << SYSTEM_COLOR << "Which filter do you want?\n1) Grayscale Conversion.\n2) Black and White.\n3) Invert Image.\n4) Merge Images.\n5) Flip Image.\n6) Rotate Image.\n7) Darken and Lighten Image.\n8) Crop Images.\n9) Exit\n"
             << RESET_COLOR;
        choice = get_int("Enter your choice: ");
        while (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7  && choice != 8  && choice != 9  && choice != 10)
        {
            cout << RED << "Invalid input! PLease, Follow the instructions.\n"
                 << RESET_COLOR;
            cout << SYSTEM_COLOR << "Which filter do you want?\n1) Grayscale Conversion.\n2) Black and White.\n3) Invert Image.\n4) Merge Images.\n5) Flip Image.\n6) Rotate Image.\n7) Darken and Lighten Image.\n8) Crop Images.\n9) Exit\n"
                 << RESET_COLOR;
            choice = get_int("Enter your choice: ");
        }

        if (choice == 1)
        {
            gray_scale();
        }
        else if (choice == 2)
        {
            Black_and_White();
        }
        else if (choice == 3)
        {
            Invert_Image();
        }
        else if (choice == 4)
        {
            Merge_Images();
        }
        else if (choice == 5)
        {
            Flip_Image();
        }
        else if (choice == 6)
        {
            Rotate_Image();
        }
        else if (choice == 7)
        {
            Darken_and_Lighten_Image();
        }
        else if (choice == 8)
        {
            Crop_Images();
        }
        else if (choice == 9)
        {
            cout << SYSTEM_COLOR << "Thanks for using the program! 🥰" << RESET_COLOR;
            break;
        }
        else
        {
            cout << RED << "Invalid choice, please follow the instructions\n"
                 << RESET_COLOR;
        }
    }

    return 0;
}
int get_int(const string &message = "")
{
    int num = 0;
    cout << SYSTEM_COLOR << message << RESET_COLOR;
    cin >> num;
    while (cin.fail())
    {
        cout << RED << "Invalid Input! Please, follow the instructions\n"
             << RESET_COLOR;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << message << RESET_COLOR;
        cin >> num;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return num;
}
string color()
{
    int color;
    string player_color;
    cout << BOLD << "Chose system color \n(1) Blue\n(2) Yellow\n(3) White\n(4) Green\n(5) Cyan\n(6) Purple\n"
         << RESET_COLOR;
    color = get_int();
    while (color != 1 && color != 2 && color != 3 && color != 4 && color != 5 && color != 6)
    {
        cout << RED << "Invalid color. Please choose again\n"
             << RESET_COLOR;
        cout << BOLD << "What is your favorite color?\n(1) Blue\n(2) Yellow\n(3) White\n(4) Green\n(5) Cyan\n(6) Purple\n"
             << RESET_COLOR;
        color = get_int();
    }
    if (color == 1)
        player_color = BLUE;
    else if (color == 2)
        player_color = YELLOW;
    else if (color == 3)
        player_color = WHITE;
    else if (color == 4)
        player_color = GREEN;
    else if (color == 5)
        player_color = CYAN;
    else
        player_color = PURPLE;
    return player_color;
}
//=================================================================================================================
Image gray_scale()
{
    string filename;
    cout  << SYSTEM_COLOR << "Pls enter colored image name to turn to gray scale: "<< RESET_COLOR;
    cin >> filename;
    Image image(filename);
    char choice;

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int average = 0;

            for (int k = 0; k < 3; ++k) {
                average += image(i, j, k);
            }
            average /= 3;
            for (int k = 0; k < 3; k++)
            {
                image(i, j, k) = average;
            }
        }
    }
    cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
         << "a)Yes\n"
         << "b)No\n"
         << RESET_COLOR;
    cin >> choice;
    if (choice == 'a')
    {
        image.saveImage(filename);
        system(filename.c_str());
    }
    else if (choice == 'b')
    {
        cout  << SYSTEM_COLOR << "Pls enter image name to store new image\n" << RESET_COLOR;
        cout << SYSTEM_COLOR << "and specify extension .jpg, .bmp, .png, .tga: " << RESET_COLOR;
        cin >> filename;
        image.saveImage(filename);
        system(filename.c_str());
    }
    return image;
}
//====================================================================================================================
Image Merge_Images()
{
    string frst_photo, scnd_photo , merged_name;
    cout << SYSTEM_COLOR << "Pls enter first image name : " << RESET_COLOR;
    cin >> frst_photo;
    cout << SYSTEM_COLOR << "Pls enter second image name : " << RESET_COLOR;
    cin >> scnd_photo;
    Image frst(frst_photo), scnd(scnd_photo);
    int min_width = min(frst.width, scnd.width);
    int min_height = min(frst.height, scnd.height);
    for (int i = 0; i < min_width; ++i) {
        for (int j = 0; j < min_height; ++j) {

            frst(i, j, 0) = (frst(i, j, 0) + scnd(i, j, 0)) / 2;
            frst(i, j, 1) = (frst(i, j, 1) + scnd(i, j, 1)) / 2;
            frst(i, j, 2) = (frst(i, j, 2) + scnd(i, j, 2)) / 2;
        }
    }
    cout << SYSTEM_COLOR << "Pls enter image name to store new image\n" << RESET_COLOR;
    cout << SYSTEM_COLOR << "and specify extension .jpg, .bmp, .png, .tga: " << RESET_COLOR;
    cin >> merged_name;
    frst.saveImage(merged_name);
    system(merged_name.c_str());
    return frst;
}
//====================================================================================================================
Image Darken_and_Lighten_Image()
{
    string filename;
    cout << SYSTEM_COLOR << "Pls enter colored image name: " << RESET_COLOR;
    cin >> filename;
    Image image(filename);
    char choice1 , choice2;
    cout << SYSTEM_COLOR << "What do you want to do ?\n"
         << "a)Lighten Image\n"
         << "b)Darken Image\n"
         << "choice:"
         << RESET_COLOR;
    cin >> choice1;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            if (choice1 == 'a')
            {
                image(i, j, 0) = min(image(i, j, 0) * 2, 255);
                image(i, j, 1) = min(image(i, j, 1) * 2, 255);
                image(i, j, 2) = min(image(i, j, 2) * 2, 255);
            }
            else if (choice1 == 'b')
            {
                image(i, j, 0) = image(i, j, 0) / 2;
                image(i, j, 1) = image(i, j, 1) / 2;
                image(i, j, 2) = image(i, j, 2) / 2;
            }
        }
    }
    cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
         << "a)Yes\n"
         << "b)No\n"
         << RESET_COLOR;
    cin >> choice2;
    if (choice2 == 'a')
    {
        image.saveImage(filename);
        system(filename.c_str());
    }
    else if (choice2 == 'b')
    {
        cout << SYSTEM_COLOR << "Pls enter image name to store new image\n" << RESET_COLOR;
        cout << SYSTEM_COLOR << "and specify extension .jpg, .bmp, .png, .tga: " << RESET_COLOR;
        cin >> filename;
        image.saveImage(filename);
        system(filename.c_str());
    }
    return image;
}
//=====================================================================================================================
int Black_and_White() {
    string filename;
    cout << SYSTEM_COLOR << "Please, enter the colored image name to turn it to a black and wight image: " << RESET_COLOR;
    cin >> filename;

    Image image(filename);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int avg = 0; // Initialize average value

            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k); // Accumulate pixel values
            }

            avg /= 3; // Calculate average
            for (int k = 0; k < 3; ++k) {
                if (avg > 127){
                    image(i, j, k) = 255 ;
                }
                else if (avg <= 127){
                    image(i, j, k) = 0 ;
                }
            }

        }
    }

    cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \n" << RESET_COLOR;
    cout << SYSTEM_COLOR << "and specify extension .jpg, .bmp, .png, .tga: " << RESET_COLOR << endl ;

    cin >> filename;
    image.saveImage(filename);

    string choice;
    while (true){
        cout << SYSTEM_COLOR << "\nDo you want to try again:\n1)Yes\n2)No" << RESET_COLOR;
        cin >> choice;
        if (choice == "1" ) {
            Black_and_White();
        } else if (choice == "2") {
            break;
        }
        else { cout << RED << "Please, enter a valid input."  << RESET_COLOR;}
    }
    return 0;
}
//====================================================================================================================
int vertical_flip(){
    string filename;
    cout << SYSTEM_COLOR << "Please,enter the name of the image you want to flip:" << RESET_COLOR;
    cin >> filename;
    Image image(filename);
    Image image2 (image.width,image.height);


    for (int i = 0; i < image2.width; ++i) {
        for (int j = 0; j < image2.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image2(i,(j),k) = image(i, (image.height - j - 1), k); // Accumulate pixel values
            }

        }
    }

    cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;

    cin >> filename;
    image2.saveImage(filename);

    return 0;

}
int horizontal_flip(){
    string filename;
    cout << SYSTEM_COLOR << "Please,enter the name of the image you want to flip:" << RESET_COLOR;
    cin >> filename;
    Image image(filename);
    Image image2 (image.width,image.height);


    for (int i = 0; i < image2.width; ++i) {
        for (int j = 0; j < image2.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image2(i,j,k) = image(image.width - i - 1, j, k); // Accumulate pixel values
            }

        }
    }

    cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;

    cin >> filename;
    image2.saveImage(filename);

    return 0;


}
int Flip_Image() {
    string filename;
    string choice;
    while (true){
        cout << SYSTEM_COLOR << "What kind of flip do you want: \n1)Vertical flip\n2)Horizontal flip\n3)Exit" << RESET_COLOR << endl;
        cin >> choice;
        if (choice == "1" ) {
            vertical_flip();
        } else if (choice == "2") {
            horizontal_flip();
        }
        else if (choice == "3"){
            break;
        }
        else { cout << RED << "Please, enter a valid input."  << RESET_COLOR;}
    }

    return 0;
}
//======================================================================================================================
int Crop_Images() {
    string filename;
    int width, height, x, y;
    cout << SYSTEM_COLOR << "Please, enter the image name to crop it:" << RESET_COLOR << endl;
    cin >> filename;

    Image image(filename);

    while (true) {
        cout << SYSTEM_COLOR << "Please, enter the first coordinates of the starting point to crop the image (x):" << RESET_COLOR << endl;
        cin >> x;
        cout << SYSTEM_COLOR << "Please, enter the second coordinates of the starting point to crop the image (y):" << RESET_COLOR << endl;
        cin >> y;
        cout << SYSTEM_COLOR << "Please, enter the colored image width:" << RESET_COLOR << endl;
        cin >> width;
        cout << SYSTEM_COLOR << "Please, enter the colored image height:" << RESET_COLOR << endl;
        cin >> height;
        if ((x + width > image.width)  && (y + height > image.height) ){
            cout << RED << "The dimensions is not valid to crop,please try again." << RESET_COLOR << endl;
        }
        else { break;}
    }
    Image image2(width,height);

    for (int i = x ; i < x + image2.width; ++i) {
        for (int j = y ; j < y + image2.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image2(i - x ,j - y ,k) = image(i, j, k); // Accumulate pixel values
            }
        }
    }

    cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \n" << RESET_COLOR;
    cout << SYSTEM_COLOR << "and specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;
    cin >> filename;
    image2.saveImage(filename);

    string choice;
    while (true){
        cout << SYSTEM_COLOR << "\nDo you want to try again:\n1)Yes\n2)No" << RESET_COLOR << endl;
        cin >> choice;
        if (choice == "1" ) {
            Crop_Images();
        } else if (choice == "2") {
            break;
        }
        else { cout << RED << "Please, enter a valid input."  << RESET_COLOR;}
    }
    return 0;
}
// File: CS112_A3_Part1_Section11,12_20231167_20231039_20231200.cpp
// Purpose: The program do a variety of filters on images.
// Author: Gamal Megahed Sayed Mohamed (20231039) (eng.gamalmegahed@gmail.com), Section 12 , Did Filter_1 , Filter_4 , Filter_7.
//         Mostafa Ehab Mostafa Akl (20231167) (mostafaehabakl@gmail.com) , Section 12 , Did Filter_2 , Filter_5 , Filter_8.
//         Walid Adel Mordy Rohyem (20231200) (khattabadel112005@gmail.com), Section 11 , Did Filter_3 . Filter_6.
//=================================================================================================================================
#include <bits/stdc++.h>
#include "Image_Class.h"
using namespace std;
string SYSTEM_COLOR;
string RESET_COLOR = "\033[0m";
string BOLD = "\033[1;37m";
string RED = "\033[1;31m";
string BLUE = "\033[1;34m";
string YELLOW = "\033[1;33m";
string WHITE = "\033[1;37m";
string GREEN = "\033[1;32m";
string CYAN = "\033[1;36m";
string PURPLE = "\033[1;35m";

int Invert_Image(){
    while (true){
        string filename,SYSTEM_COLOR,RESET_COLOR;
        cout << SYSTEM_COLOR << "Please,enter the name of the image you want to invert with (.png, .jpeg, .jpg, .bmp): " << RESET_COLOR;
        cin >> filename;
        Image khattab_image(filename);
        while(true){
            try {
                khattab_image.loadNewImage(filename);
                break;
            } catch( invalid_argument) {
                cout << "Please enter a valid photo \n" << endl;
                cin>>filename;
            }
        }

        for (int i = 0  ; i < khattab_image.width ; i++){
            for (int j = 0 ; j < khattab_image.height ; j++){
                unsigned int avg = 0;
                for (int k = 0 ; k < 3 ; k++){
                    khattab_image(i , j , k)=255- khattab_image(i,j,k);

                }
            }
        }
        cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;
        cin >> filename;
        khattab_image.saveImage(filename);
        cout<<SYSTEM_COLOR<<"Done Succefully!"<<RESET_COLOR<<endl;
        int choice;
        cout<<SYSTEM_COLOR<<"Do you want to restart again\n1)YES\n2)NO: "<<RESET_COLOR;
        cin>>choice;
        while (cin.fail()||(choice!=1 && choice!=2) ){
            cout<<SYSTEM_COLOR<<"Invalid input! Plaese, Follow the instructions."<<RESET_COLOR<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<SYSTEM_COLOR<<"Do you want to restart again\n1)YES\n2)NO: "<<RESET_COLOR;
            cin>>choice;
        }
        if (choice==2)break;}

    return 0;}
//====================================================================================================================
int Rotate_Image(){
    while (true){
        string filename,SYSTEM_COLOR,RESET_COLOR;
        cout << SYSTEM_COLOR << "Please,enter the name of the image you want to rotate with (.png, .jpeg, .jpg, .bmp): " << RESET_COLOR;
        cin >> filename;
        Image khattab_image(filename);
        while(true){
            try {
                khattab_image.loadNewImage(filename);
                break;
            } catch( invalid_argument) {
                cout << "Please enter a valid photo \n" << endl;
                cin>>filename;
            }
        }

        int angle;
        cout<<SYSTEM_COLOR<<"Enter the Angle ( 90 , 180 , 270 ,360): "<<RESET_COLOR;
        cin>>angle;
        while (cin.fail()||(angle!=90 && angle !=180 && angle!=270 && angle!=360) ){
            cout<<SYSTEM_COLOR<<"Invalid input! Plaese, Follow the instructions."<<RESET_COLOR<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<SYSTEM_COLOR<<"Enter the Angle ( 90 , 180 , 270 , 360 ): "<<RESET_COLOR;
            cin>>angle;
        }
        if (angle == 90){

            Image khattab_image2(khattab_image.height,khattab_image.width);
            for (int i = 0 ; i < khattab_image.width ; i++){
                for (int j = 0 ; j < khattab_image.height ; j++){
                    for (int k = 0 ; k < 3 ; k++){
                        khattab_image2(khattab_image.height-j-1,i,k)=khattab_image( i , j , k );
                    }
                }
            }
            cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;
            cin >> filename;
            khattab_image2.saveImage(filename);
            cout<<SYSTEM_COLOR<<"Done Succefully!"<<RESET_COLOR<<endl;
        }
        else if (angle==180){
            // Load the original image
            Image khattab_image2(khattab_image.width, khattab_image.height); // Create a new image with the same dimensions

            // Iterate over the original image pixels and copy them to the rotated image with adjusted coordinates
            for (int i = 0; i < khattab_image.width; i++) {
                for (int j = 0; j < khattab_image.height; j++) {
                    for (int k = 0; k < 3; k++) {
                        // Copy pixel from original image to rotated image with adjusted coordinates for 180-degree rotation
                        khattab_image2(khattab_image.width - i - 1, khattab_image.height - j - 1, k) = khattab_image(i, j, k);
                    }
                }
            }

            cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;
            cin >> filename;
            khattab_image2.saveImage(filename);
            cout<<SYSTEM_COLOR<<"Done Succefully!"<<RESET_COLOR<<endl;
        }
        else if (angle == 270){ // Load the original image
            Image khattab_image2(khattab_image.height, khattab_image.width); // Create a new image with swapped dimensions

            // Iterate over the original image pixels and copy them to the rotated image with swapped coordinates
            for (int i = 0; i < khattab_image.width; i++) {
                for (int j = 0; j < khattab_image.height; j++) {
                    for (int k = 0; k < 3; k++) {
                        // Copy pixel from original image to rotated image with swapped coordinates
                        khattab_image2(j, khattab_image.width - i - 1, k) = khattab_image(i, j, k);
                    }
                }
            }
            cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;
            cin >> filename;
            khattab_image2.saveImage(filename);
            cout<<SYSTEM_COLOR<<"Done Succefully!"<<RESET_COLOR<<endl;}
        else if ( angle == 360){
            Image khattab_image2(khattab_image.width,khattab_image.height);
            for (int i = 0 ; i < khattab_image.width ; i++){
                for (int j = 0 ; j < khattab_image.height ; j++){
                    for (int k = 0 ; k < 3 ; k++){
                        khattab_image2(i,j,k)=khattab_image( i , j , k );
                    }
                }
            }
            cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;
            cin >> filename;
            khattab_image2.saveImage(filename);
            cout<<SYSTEM_COLOR<<"Done Succefully!"<<RESET_COLOR<<endl;
        }
        int choice;
        cout<<SYSTEM_COLOR<<"Do you want to restart again\n1)YES\n2)NO: "<<RESET_COLOR;
        cin>>choice;
        while (cin.fail()||(choice!=1 && choice!=2) ){
            cout<<SYSTEM_COLOR<<"Invalid input! Plaese, Follow the instructions."<<RESET_COLOR<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<SYSTEM_COLOR<<"Do you want to restart again\n1)YES\n2)NO: "<<RESET_COLOR;
            cin>>choice;
        }
        if (choice==2)break;}

    return 0;

}

int get_int(const string&);
string color();
Image gray_scale();
Image Merge_Images();
Image Darken_and_Lighten_Image();
int Black_and_White();
int Flip_Image();
int Crop_Images();

int main()
{
    int choice;
    cout << BOLD << "🤩🥰❤ Ahllan Ya User Ya Habyby ❤🥰🤩\n"
         << RESET_COLOR;
    SYSTEM_COLOR = color();
    cout << "\n============\n";
    while (true)
    {
        cout << SYSTEM_COLOR << "Which filter do you want?\n1) Grayscale Conversion.\n2) Black and White.\n3) Invert Image.\n4) Merge Images.\n5) Flip Image.\n6) Rotate Image.\n7) Darken and Lighten Image.\n8) Crop Images.\n9) Exit\n"
             << RESET_COLOR;
        choice = get_int("Enter your choice: ");
        while (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7  && choice != 8  && choice != 9  && choice != 10)
        {
            cout << RED << "Invalid input! PLease, Follow the instructions.\n"
                 << RESET_COLOR;
            cout << SYSTEM_COLOR << "Which filter do you want?\n1) Grayscale Conversion.\n2) Black and White.\n3) Invert Image.\n4) Merge Images.\n5) Flip Image.\n6) Rotate Image.\n7) Darken and Lighten Image.\n8) Crop Images.\n9) Exit\n"
                 << RESET_COLOR;
            choice = get_int("Enter your choice: ");
        }

        if (choice == 1)
        {
            gray_scale();
        }
        else if (choice == 2)
        {
            Black_and_White();
        }
        else if (choice == 3)
        {
            Invert_Image();
        }
        else if (choice == 4)
        {
            Merge_Images();
        }
        else if (choice == 5)
        {
            Flip_Image();
        }
        else if (choice == 6)
        {
            Rotate_Image();
        }
        else if (choice == 7)
        {
            Darken_and_Lighten_Image();
        }
        else if (choice == 8)
        {
            Crop_Images();
        }
        else if (choice == 9)
        {
            cout << SYSTEM_COLOR << "Thanks for using the program! 🥰" << RESET_COLOR;
            break;
        }
        else
        {
            cout << RED << "Invalid choice, please follow the instructions\n"
                 << RESET_COLOR;
        }
    }

    return 0;
}
int get_int(const string &message = "")
{
    int num = 0;
    cout << SYSTEM_COLOR << message << RESET_COLOR;
    cin >> num;
    while (cin.fail())
    {
        cout << RED << "Invalid Input! Please, follow the instructions\n"
             << RESET_COLOR;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << message << RESET_COLOR;
        cin >> num;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return num;
}
string color()
{
    int color;
    string player_color;
    cout << BOLD << "Chose system color \n(1) Blue\n(2) Yellow\n(3) White\n(4) Green\n(5) Cyan\n(6) Purple\n"
         << RESET_COLOR;
    color = get_int();
    while (color != 1 && color != 2 && color != 3 && color != 4 && color != 5 && color != 6)
    {
        cout << RED << "Invalid color. Please choose again\n"
             << RESET_COLOR;
        cout << BOLD << "What is your favorite color?\n(1) Blue\n(2) Yellow\n(3) White\n(4) Green\n(5) Cyan\n(6) Purple\n"
             << RESET_COLOR;
        color = get_int();
    }
    if (color == 1)
        player_color = BLUE;
    else if (color == 2)
        player_color = YELLOW;
    else if (color == 3)
        player_color = WHITE;
    else if (color == 4)
        player_color = GREEN;
    else if (color == 5)
        player_color = CYAN;
    else
        player_color = PURPLE;
    return player_color;
}
//=================================================================================================================
Image gray_scale()
{
    string filename;
    cout  << SYSTEM_COLOR << "Pls enter colored image name to turn to gray scale: "<< RESET_COLOR;
    cin >> filename;
    Image image(filename);
    char choice;

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int average = 0;

            for (int k = 0; k < 3; ++k) {
                average += image(i, j, k);
            }
            average /= 3;
            for (int k = 0; k < 3; k++)
            {
                image(i, j, k) = average;
            }
        }
    }
    cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
         << "a)Yes\n"
         << "b)No\n"
         << RESET_COLOR;
    cin >> choice;
    if (choice == 'a')
    {
        image.saveImage(filename);
        system(filename.c_str());
    }
    else if (choice == 'b')
    {
        cout  << SYSTEM_COLOR << "Pls enter image name to store new image\n" << RESET_COLOR;
        cout << SYSTEM_COLOR << "and specify extension .jpg, .bmp, .png, .tga: " << RESET_COLOR;
        cin >> filename;
        image.saveImage(filename);
        system(filename.c_str());
    }
    return image;
}
//====================================================================================================================
Image Merge_Images()
{
    string frst_photo, scnd_photo , merged_name;
    cout << SYSTEM_COLOR << "Pls enter first image name : " << RESET_COLOR;
    cin >> frst_photo;
    cout << SYSTEM_COLOR << "Pls enter second image name : " << RESET_COLOR;
    cin >> scnd_photo;
    Image frst(frst_photo), scnd(scnd_photo);
    int min_width = min(frst.width, scnd.width);
    int min_height = min(frst.height, scnd.height);
    for (int i = 0; i < min_width; ++i) {
        for (int j = 0; j < min_height; ++j) {

            frst(i, j, 0) = (frst(i, j, 0) + scnd(i, j, 0)) / 2;
            frst(i, j, 1) = (frst(i, j, 1) + scnd(i, j, 1)) / 2;
            frst(i, j, 2) = (frst(i, j, 2) + scnd(i, j, 2)) / 2;
        }
    }
    cout << SYSTEM_COLOR << "Pls enter image name to store new image\n" << RESET_COLOR;
    cout << SYSTEM_COLOR << "and specify extension .jpg, .bmp, .png, .tga: " << RESET_COLOR;
    cin >> merged_name;
    frst.saveImage(merged_name);
    system(merged_name.c_str());
    return frst;
}
//====================================================================================================================
Image Darken_and_Lighten_Image()
{
    string filename;
    cout << SYSTEM_COLOR << "Pls enter colored image name: " << RESET_COLOR;
    cin >> filename;
    Image image(filename);
    char choice1 , choice2;
    cout << SYSTEM_COLOR << "What do you want to do ?\n"
         << "a)Lighten Image\n"
         << "b)Darken Image\n"
         << "choice:"
         << RESET_COLOR;
    cin >> choice1;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            if (choice1 == 'a')
            {
                image(i, j, 0) = min(image(i, j, 0) * 2, 255);
                image(i, j, 1) = min(image(i, j, 1) * 2, 255);
                image(i, j, 2) = min(image(i, j, 2) * 2, 255);
            }
            else if (choice1 == 'b')
            {
                image(i, j, 0) = image(i, j, 0) / 2;
                image(i, j, 1) = image(i, j, 1) / 2;
                image(i, j, 2) = image(i, j, 2) / 2;
            }
        }
    }
    cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
         << "a)Yes\n"
         << "b)No\n"
         << RESET_COLOR;
    cin >> choice2;
    if (choice2 == 'a')
    {
        image.saveImage(filename);
        system(filename.c_str());
    }
    else if (choice2 == 'b')
    {
        cout << SYSTEM_COLOR << "Pls enter image name to store new image\n" << RESET_COLOR;
        cout << SYSTEM_COLOR << "and specify extension .jpg, .bmp, .png, .tga: " << RESET_COLOR;
        cin >> filename;
        image.saveImage(filename);
        system(filename.c_str());
    }
    return image;
}
//=====================================================================================================================
int Black_and_White() {
    string filename;
    cout << SYSTEM_COLOR << "Please, enter the colored image name to turn it to a black and wight image: " << RESET_COLOR;
    cin >> filename;

    Image image(filename);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int avg = 0; // Initialize average value

            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k); // Accumulate pixel values
            }

            avg /= 3; // Calculate average
            for (int k = 0; k < 3; ++k) {
                if (avg > 127){
                    image(i, j, k) = 255 ;
                }
                else if (avg <= 127){
                    image(i, j, k) = 0 ;
                }
            }

        }
    }

    cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \n" << RESET_COLOR;
    cout << SYSTEM_COLOR << "and specify extension .jpg, .bmp, .png, .tga: " << RESET_COLOR << endl ;

    cin >> filename;
    image.saveImage(filename);

    string choice;
    while (true){
        cout << SYSTEM_COLOR << "\nDo you want to try again:\n1)Yes\n2)No" << RESET_COLOR;
        cin >> choice;
        if (choice == "1" ) {
            Black_and_White();
        } else if (choice == "2") {
            break;
        }
        else { cout << RED << "Please, enter a valid input."  << RESET_COLOR;}
    }
    return 0;
}
//====================================================================================================================
int vertical_flip(){
    string filename;
    cout << SYSTEM_COLOR << "Please,enter the name of the image you want to flip:" << RESET_COLOR;
    cin >> filename;
    Image image(filename);
    Image image2 (image.width,image.height);


    for (int i = 0; i < image2.width; ++i) {
        for (int j = 0; j < image2.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image2(i,(j),k) = image(i, (image.height - j - 1), k); // Accumulate pixel values
            }

        }
    }

    cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;

    cin >> filename;
    image2.saveImage(filename);

    return 0;

}
int horizontal_flip(){
    string filename;
    cout << SYSTEM_COLOR << "Please,enter the name of the image you want to flip:" << RESET_COLOR;
    cin >> filename;
    Image image(filename);
    Image image2 (image.width,image.height);


    for (int i = 0; i < image2.width; ++i) {
        for (int j = 0; j < image2.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image2(i,j,k) = image(image.width - i - 1, j, k); // Accumulate pixel values
            }

        }
    }

    cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;

    cin >> filename;
    image2.saveImage(filename);

    return 0;


}
int Flip_Image() {
    string filename;
    string choice;
    while (true){
        cout << SYSTEM_COLOR << "What kind of flip do you want: \n1)Vertical flip\n2)Horizontal flip\n3)Exit" << RESET_COLOR << endl;
        cin >> choice;
        if (choice == "1" ) {
            vertical_flip();
        } else if (choice == "2") {
            horizontal_flip();
        }
        else if (choice == "3"){
            break;
        }
        else { cout << RED << "Please, enter a valid input."  << RESET_COLOR;}
    }

    return 0;
}
//======================================================================================================================
int Crop_Images() {
    string filename;
    int width, height, x, y;
    cout << SYSTEM_COLOR << "Please, enter the image name to crop it:" << RESET_COLOR << endl;
    cin >> filename;

    Image image(filename);

    while (true) {
        cout << SYSTEM_COLOR << "Please, enter the first coordinates of the starting point to crop the image (x):" << RESET_COLOR << endl;
        cin >> x;
        cout << SYSTEM_COLOR << "Please, enter the second coordinates of the starting point to crop the image (y):" << RESET_COLOR << endl;
        cin >> y;
        cout << SYSTEM_COLOR << "Please, enter the colored image width:" << RESET_COLOR << endl;
        cin >> width;
        cout << SYSTEM_COLOR << "Please, enter the colored image height:" << RESET_COLOR << endl;
        cin >> height;
        if ((x + width > image.width)  && (y + height > image.height) ){
            cout << RED << "The dimensions is not valid to crop,please try again." << RESET_COLOR << endl;
        }
        else { break;}
    }
    Image image2(width,height);

    for (int i = x ; i < x + image2.width; ++i) {
        for (int j = y ; j < y + image2.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image2(i - x ,j - y ,k) = image(i, j, k); // Accumulate pixel values
            }
        }
    }

    cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \n" << RESET_COLOR;
    cout << SYSTEM_COLOR << "and specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;
    cin >> filename;
    image2.saveImage(filename);

    string choice;
    while (true){
        cout << SYSTEM_COLOR << "\nDo you want to try again:\n1)Yes\n2)No" << RESET_COLOR << endl;
        cin >> choice;
        if (choice == "1" ) {
            Crop_Images();
        } else if (choice == "2") {
            break;
        }
        else { cout << RED << "Please, enter a valid input."  << RESET_COLOR;}
    }
    return 0;
}
