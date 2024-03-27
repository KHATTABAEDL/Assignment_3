// File: CS112_A3_Part1_Section11,12_20231167_20231039_20231200.cpp
// Purpose: The program do a variety of filters on images.

// Author:
// -Gamal Megahed Sayed Mohamed (20231039) (eng.gamalmegahed@gmail.com), Section 12 , Did Filter_1 , Filter_4 , Filter_7.
// -Mostafa Ehab Mostafa Akl (20231167) (mostafaehabakl@gmail.com) , Section 12 , Did Filter_2 , Filter_5 , Filter_8.
// -Walid Adel Mordy Rohyem (20231200) (khattabadel112005@gmail.com), Section 11 , Did Filter_3 . Filter_6.
//=================================================================================================================================
#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>
#include <cstdio>
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

int get_int(const string&);
string color();
Image Gamal_gray_scale(string);
Image Gamal_Merge_Images(string);
Image Gamal_Darken_and_Lighten_Image(string);
Image Black_and_White(string);
Image Flip_Image(string);
Image Crop_Images(string);
Image Rotate_Image(string);
Image Invert_Image(string);
string get_image(string);
bool valid_exe(string);
//string saveBefore(bool);
bool unsaved_image = false;
Image saved_image;
int main()
{
    string filename;
    system("color");
    int choice;
    cout << BOLD << "🤩🥰❤ Ahllan Ya User Ya Habyby ❤🥰🤩\n"
        << RESET_COLOR;
    SYSTEM_COLOR = color();
    cout << "\n============\n";
    
    filename = get_image(SYSTEM_COLOR + "Enter the file(image) you want to do filters on:" + RESET_COLOR);

    while (true)
    {
        cout << SYSTEM_COLOR << "Which filter do you want?\n0) Load a new image.\n1) Grayscale Conversion.\n2) Black and White.\n3) Invert Image.\n4) Merge Images.\n5) Flip Image.\n6) Rotate Image.\n7) Darken and Lighten Image.\n8) Crop Images.\n9) Save the image.\n10) Exit\n"
            << RESET_COLOR;
        choice = get_int("Enter your choice: ");
        while (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9 && choice != 10)
        {
            cout << RED << "Invalid input! PLease, Follow the instructions.\n"
                << RESET_COLOR;
            cout << SYSTEM_COLOR << "Which filter do you want?\n0) Load a new image.\n1) Grayscale Conversion.\n2) Black and White.\n3) Invert Image.\n4) Merge Images.\n5) Flip Image.\n6) Rotate Image.\n7) Darken and Lighten Image.\n8) Crop Images.\n9) Save the image.\n10) Exit\n"
                << RESET_COLOR;
            choice = get_int("Enter your choice: ");
        }
        if (choice == 0)
        {
            //            LoadNewImage();
            if (unsaved_image) {
                bool flag = true;
                string ch;
                while (flag) {
                    cout << SYSTEM_COLOR << "Do you want to save your changes on the last image:\n1)Yes\n2)No" << RESET_COLOR;
                    cin >> ch;
                    if (ch == "1") {
                        char c;
                        cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
                            << "a)Yes\n"
                            << "b)No\n" << RESET_COLOR;
                        cin >> c;
                        while (c != 'a' && c != 'b')
                        {
                            cout << RED << "invalid choice\n" << RESET_COLOR;
                            cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
                                << "a)Yes\n"
                                << "b)No\n" << RESET_COLOR;
                            cin >> c;
                        }
                        if (c == 'a')
                        {
                            saved_image.saveImage(filename);
                            system(filename.c_str());
                        }
                        else if (c == 'b')
                        {
                            cout << "Pls enter image name to store new image\n";
                            cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                            cin >> filename;
                            saved_image.saveImage(filename);
                            system(filename.c_str());
                        }

                        flag = false;
                    }
                    else if (ch == "2") {
                        cout << SYSTEM_COLOR << "Enter the name of the file you want to do the filters on:" << RESET_COLOR;
                        cin >> filename;
                        flag = false;
                    }
                    else
                    {
                        cout << RED << "Invalid choice, please follow the instructions\n"
                            << RESET_COLOR;
                    }

                }
            }
            else {
                cout << SYSTEM_COLOR << "Enter the name of the file you want to do the filters on:" << RESET_COLOR;
                cin >> filename;
            }
            //            saveBefore(unsaved_image);
        }
        else if (choice == 1)
        {
            remove("saved.jpg");
            Gamal_gray_scale(filename);
        }
        else if (choice == 2)
        {
            remove("saved.jpg");
            Black_and_White(filename);
        }
        else if (choice == 3)
        {
            remove("saved.jpg");
            Invert_Image(filename);
        }
        else if (choice == 4)
        {
            remove("saved.jpg");
            Gamal_Merge_Images(filename);
        }
        else if (choice == 5)
        {
            remove("saved.jpg");
            Flip_Image(filename);
        }
        else if (choice == 6)
        {
            remove("saved.jpg");
            Rotate_Image(filename);
        }
        else if (choice == 7)
        {
            remove("saved.jpg");
            Gamal_Darken_and_Lighten_Image(filename);
        }
        else if (choice == 8)
        {
            remove("saved.jpg");
            Crop_Images(filename);
        }
        else if (choice == 9)
        {
            char c;
            cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
                << "a)Yes\n"
                << "b)No\n" << RESET_COLOR;
            cin >> c;
            while (c != 'a' && c != 'b')
            {
                cout << RED << "invalid choice\n" << RESET_COLOR;
                cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
                    << "a)Yes\n"
                    << "b)No\n" << RESET_COLOR;
                cin >> c;
            }
            if (c == 'a')
            {
                string new_filename = filename, old_filename = "saved.jpg";;
                remove(filename.c_str());
                rename(old_filename.c_str(), new_filename.c_str());
                system(filename.c_str());
            }
            else if (c == 'b')
            {
                string new_filename , old_filename = "saved.jpg";;
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                cin >> new_filename;
                while (!valid_exe(new_filename))
                {
                    cout << RED << "Invalid extention, please follow the instructions\n" << RESET_COLOR;
                    cout << SYSTEM_COLOR <<  "Pls enter image name to store new image\n";
                    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                    cin >> new_filename;
                }
                rename(old_filename.c_str(), new_filename.c_str());
                system(new_filename.c_str());
            }
        }
        else if (choice == 10)
        {
            if (unsaved_image)
            {
                bool flag = true;
                string ch;
                while (flag) {
                    cout << SYSTEM_COLOR << "Do you want to save your changes on the last image:\n1)Yes\n2)No" << RESET_COLOR;
                    cin >> ch;
                    if (ch == "1") {
                        char c;
                        cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
                            << "a)Yes\n"
                            << "b)No\n" << RESET_COLOR;
                        cin >> c;
                        while (c != 'a' && c != 'b')
                        {
                            cout << RED << "invalid choice\n" << RESET_COLOR;
                            cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
                                << "a)Yes\n"
                                << "b)No\n" << RESET_COLOR;
                            cin >> c;
                        }
                        if (c == 'a')
                        {
                            string new_filename = filename, old_filename = "saved.jpg";;
                            remove(filename.c_str());
                            rename(old_filename.c_str(), new_filename.c_str());
                            system(filename.c_str());
                        }
                        else if (c == 'b')
                        {
                            string new_filename, old_filename = "saved.jpg";;
                            cout << "Pls enter image name to store new image\n";
                            cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                            cin >> new_filename;
                            while (!valid_exe(new_filename))
                            {
                                cout << RED << "Invalid extention, please follow the instructions\n" << RESET_COLOR;
                                cout << SYSTEM_COLOR << "Pls enter image name to store new image\n";
                                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                                cin >> new_filename;
                            }
                            rename(old_filename.c_str(), new_filename.c_str());
                            system(new_filename.c_str());
                        }
                        flag = false;
                    }
                    else if (ch == "2") {
                        remove("saved.jpg");
                        cout << SYSTEM_COLOR << "Thanks for using the program! 🥰" << RESET_COLOR;
                        return 0;
                    }
                    else
                    {
                        cout << RED << "Invalid choice, please follow the instructions\n"
                            << RESET_COLOR;
                    }

                }
            }
            else {
                cout << SYSTEM_COLOR << "Thanks for using the program! 🥰" << RESET_COLOR;
                return 0;
            }

        }
        else
        {
            cout << RED << "Invalid choice, please follow the instructions\n"
                << RESET_COLOR;
        }
    }
    return 0;
}
//===================================================================================================================
//string saveBefore(bool unsaved_image){
//    if (unsaved_image){
//        bool flag = true;
//        string ch;
//        while (flag) {
//            cout << SYSTEM_COLOR << "Do you want to save your changes on the last image:\n1)Yes\n2)No" << RESET_COLOR;
//            cin >> ch;
//            if (ch == "1"){
//
//                flag = false;
//            }
//            else if (ch == "2"){
//                cout << SYSTEM_COLOR << "Enter the name of the file you want to do the filters on:" << RESET_COLOR;
//                return cin >> filename;
//                flag = false;
//            }
//            else
//            {
//                cout << RED << "Invalid choice, please follow the instructions\n"
//                     << RESET_COLOR;
//            }
//
//        }
//    }
//
//}

string get_image(string message = "")
{
    string image_name;
    cout << message;
    cin >> image_name;
    Image image;
    while (true) {
        try {
            image.loadNewImage(image_name);
            break;
        }
        catch (invalid_argument) {
            cout << RED << "Please enter a valid photo \n" << RESET_COLOR;
            cin >> image_name;
        }
    }
    return image_name;
}
int get_int(const string& message = "")
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
        cout << BOLD << "Chose system color \n(1) Blue\n(2) Yellow\n(3) White\n(4) Green\n(5) Cyan\n(6) Purple\n"
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
//==========================================================================================================================
Image Rotate_Image(string filename) {
    // while (true){
//        cout << SYSTEM_COLOR << "Please,enter the name of the image you want to rotate with (.png, .jpeg, .jpg, .bmp): " << RESET_COLOR;
//        cin >> filename;
    Image khattab_image(filename);
    //        while(true){
    //            try {
    //                khattab_image.loadNewImage(filename);
    //                break;
    //            } catch( invalid_argument) {
    //                cout << "Please enter a valid photo \n" << endl;
    //                cin>>filename;
    //            }
    //        }

    int angle;
    cout << SYSTEM_COLOR << "Enter the Angle ( 90 , 180 , 270 ,360): " << RESET_COLOR;
    cin >> angle;
    while (cin.fail() || (angle != 90 && angle != 180 && angle != 270 && angle != 360)) {
        cout << SYSTEM_COLOR << "Invalid input! Plaese, Follow the instructions." << RESET_COLOR << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << SYSTEM_COLOR << "Enter the Angle ( 90 , 180 , 270 , 360 ): " << RESET_COLOR;
        cin >> angle;
    }
    if (angle == 90) {

        Image khattab_image2(khattab_image.height, khattab_image.width);
        for (int i = 0; i < khattab_image.width; i++) {
            for (int j = 0; j < khattab_image.height; j++) {
                for (int k = 0; k < 3; k++) {
                    khattab_image2(khattab_image.height - j - 1, i, k) = khattab_image(i, j, k);
                }
            }
        }

        //            cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;
        //            cin >> filename;
                    khattab_image2.saveImage("saved.jpg");
        //            system(filename.c_str());

        return khattab_image2;
    }
    else if (angle == 180) {
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

        //            cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;
        //            cin >> filename;
                    khattab_image2.saveImage("saved.jpg");
        //            system(filename.c_str());
        unsaved_image = true;
        return khattab_image2;
    }
    else if (angle == 270) { // Load the original image
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
        //            cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;
        //            cin >> filename;
                    khattab_image2.saveImage("saved.jpg");
        //            system(filename.c_str());
    }
    else if (angle == 360) {
        Image khattab_image2(khattab_image.width, khattab_image.height);
        for (int i = 0; i < khattab_image.width; i++) {
            for (int j = 0; j < khattab_image.height; j++) {
                for (int k = 0; k < 3; k++) {
                    khattab_image2(i, j, k) = khattab_image(i, j, k);
                }
            }
        }
        //            cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;
        //            cin >> filename;
                    khattab_image2.saveImage("saved.jpg");
        //            system(filename.c_str());
        unsaved_image = true;
        return khattab_image2;
    }
    //        int choice;
    //        cout<<SYSTEM_COLOR<<"Do you want to restart again\n1)YES\n2)NO: "<<RESET_COLOR;
    //        cin>>choice;
    //        while (cin.fail()||(choice!=1 && choice!=2) ){
    //            cout<<SYSTEM_COLOR<<"Invalid input! Plaese, Follow the instructions."<<RESET_COLOR<<endl;
    //            cin.clear();
    //            cin.ignore(numeric_limits<streamsize>::max(),'\n');
    //            cout<<SYSTEM_COLOR<<"Do you want to restart again\n1)YES\n2)NO: "<<RESET_COLOR;
    //            cin>>choice;
    //        }
    //        if (choice==2)break;}


}
//===========================================================================================

bool valid_exe(string exe) {
    // (.png, .jpeg, .jpg, .bmp)
    string validexet[]{ ".jpg",".png",".jpeg",".bmp" };
    for (int i = 0; i < exe.size(); i++) {
        if (exe[i] == '.') {
            string exet = exe.substr(i);
            for (string str : validexet) {
                if (str == exet)return true;
            }

        }
    }
    return false;
}

Image Invert_Image(string filename) {
    //    while (true) {

    //        filename = get_image(SYSTEM_COLOR + "Please,enter the name of the image you want to invert with (.png, .jpeg, .jpg, .bmp): " + RESET_COLOR);
    Image khattab_image(filename);

    for (int i = 0; i < khattab_image.width; i++) {
        for (int j = 0; j < khattab_image.height; j++) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; k++) {
                khattab_image(i, j, k) = 255 - khattab_image(i, j, k);

            }
        }
    }
    //        cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;
    //        cin >> filename;
            khattab_image.saveImage("saved.jpg");
    //        system(filename.c_str());
    unsaved_image = true;
    return khattab_image;
    //        int choice;
    //        cout << SYSTEM_COLOR << "Do you want to restart again\n1)YES\n2)NO: " << RESET_COLOR;
    //        cin >> choice;
    //        while (cin.fail() || (choice != 1 && choice != 2)) {
    //            cout << RED << "Invalid input! Plaese, Follow the instructions." << RESET_COLOR << endl;
    //            cin.clear();
    //            cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //            cout << SYSTEM_COLOR << "Do you want to restart again\n1)YES\n2)NO: " << RESET_COLOR;
    //            cin >> choice;
    //        }
    //        if (choice == 2)break;
    //    }

}
//=================================================================================================================
Image Gamal_gray_scale(string Gamal_filename)
{

    //    Gamal_filename = get_image(SYSTEM_COLOR + "Pls enter colored image name to turn to gray scale: " + RESET_COLOR);
    Image Gamal_image(Gamal_filename) ;
    //    char Gamal_choice;

    for (int Gamal_i = 0; Gamal_i < Gamal_image.width; ++Gamal_i) {
        for (int Gamal_j = 0; Gamal_j < Gamal_image.height; ++Gamal_j) {
            unsigned  int Gamal_average = 0;

            for (int Gamal_k = 0; Gamal_k < 3; ++Gamal_k) {
                Gamal_average += Gamal_image(Gamal_i, Gamal_j, Gamal_k);
            }
            Gamal_average /= 3;
            for (int Gamal_k = 0; Gamal_k < 3; Gamal_k++)
            {
                Gamal_image(Gamal_i, Gamal_j, Gamal_k) = Gamal_average;
            }
        }
    }
    //    cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
    //         << "a)Yes\n"
    //         << "b)No\n" << RESET_COLOR;
    //    cin >> Gamal_choice;
    //    while (Gamal_choice != 'a' && Gamal_choice != 'b')
    //    {
    //        cout << RED << "invalid choice\n" << RESET_COLOR;
    //        cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
    //             << "a)Yes\n"
    //             << "b)No\n" << RESET_COLOR;
    //        cin >> Gamal_choice;
    //    }
    //    if (Gamal_choice == 'a')
    //    {
    //        Gamal_image.saveImage(Gamal_filename);
    //        system(Gamal_filename.c_str());
    //    }
    //    else if (Gamal_choice == 'b')
    //    {
    //        cout << "Pls enter image name to store new image\n";
    //        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    //        cin >> Gamal_filename;
    Gamal_image.saveImage("saved.jpg");
    //        system(Gamal_filename.c_str());
    //    }
    unsaved_image = true;
    return Gamal_image;
}
//====================================================================================================================
Image Gamal_Merge_Images(string Gamal_frst_photo)
{
    string Gamal_scnd_photo, Gamal_merged_name;
    //    Gamal_frst_photo = get_image(SYSTEM_COLOR + "Pls enter first image name : ");
    Gamal_scnd_photo = get_image("Pls enter second image name : ");
    //    char Gamal_choice;
    Image Gamal_frst(Gamal_frst_photo), Gamal_scnd(Gamal_scnd_photo);
    int Gamal_min_width = min(Gamal_frst.width, Gamal_scnd.width);
    int Gamal_min_height = min(Gamal_frst.height, Gamal_scnd.height);
    Image Gamal_merged(Gamal_min_width, Gamal_min_height);
    for (int Gamal_i = 0; Gamal_i < Gamal_min_width; ++Gamal_i) {
        for (int Gamal_j = 0; Gamal_j < Gamal_min_height; ++Gamal_j) {

            Gamal_merged(Gamal_i, Gamal_j, 0) = (Gamal_frst(Gamal_i, Gamal_j, 0) + Gamal_scnd(Gamal_i, Gamal_j, 0)) / 2;
            Gamal_merged(Gamal_i, Gamal_j, 1) = (Gamal_frst(Gamal_i, Gamal_j, 1) + Gamal_scnd(Gamal_i, Gamal_j, 1)) / 2;
            Gamal_merged(Gamal_i, Gamal_j, 2) = (Gamal_frst(Gamal_i, Gamal_j, 2) + Gamal_scnd(Gamal_i, Gamal_j, 2)) / 2;
        }
    }
    //    cout << "Do you want to save changes in the same image?\n"
    //          << "a)Yes\n"
    //          << "b)No\n";
    //    cin >> Gamal_choice;
    //    while (Gamal_choice != 'a' && Gamal_choice != 'b')
    //    {
    //        cout << RED << "invalid choice\n" << RESET_COLOR;
    //        cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
    //             << "a)Yes\n"
    //             << "b)No\n";
    //        cin >> Gamal_choice;
    //    }
    //    if (Gamal_choice == 'a')
    //    {
    //        Gamal_merged.saveImage(Gamal_frst_photo);
    //        system(Gamal_frst_photo.c_str());
    //    }
    //    if (Gamal_choice == 'b')
    //    {
    //        cout << "Pls enter image name to store new image\n";
    //        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    //        cin >> Gamal_merged_name;
    Gamal_merged.saveImage("saved.jpg");
    //        system(Gamal_merged_name.c_str());
    //    }
    unsaved_image = true;
    return Gamal_merged;
}
//====================================================================================================================
Image Gamal_Darken_and_Lighten_Image(string Gamal_filename)
{
    //    string Gamal_filename;
    //    Gamal_filename = get_image(SYSTEM_COLOR + "Pls enter colored image name: ");
    Image Gamal_image(Gamal_filename);
    char Gamal_choice1, Gamal_choice2;
    cout << "What do you want to do ?\n"
        << "a)Lighten Image\n"
        << "b)Darken Image\n"
        << "choice:";
    cin >> Gamal_choice1;
    while (Gamal_choice1 != 'a' && Gamal_choice1 != 'b')
    {
        cout << RED << "invalid choice, please follow the instructions\n" << RESET_COLOR;
        cout << SYSTEM_COLOR << "What do you want to do ?\n"
            << "a)Lighten Image\n"
            << "b)Darken Image\n"
            << "choice:";
        cin >> Gamal_choice1;
    }
    for (int Gamal_i = 0; Gamal_i < Gamal_image.width; ++Gamal_i) {
        for (int Gamal_j = 0; Gamal_j < Gamal_image.height; ++Gamal_j) {
            if (Gamal_choice1 == 'a')
            {
                Gamal_image(Gamal_i, Gamal_j, 0) = min(Gamal_image(Gamal_i, Gamal_j, 0) * 2, 255);
                Gamal_image(Gamal_i, Gamal_j, 1) = min(Gamal_image(Gamal_i, Gamal_j, 1) * 2, 255);
                Gamal_image(Gamal_i, Gamal_j, 2) = min(Gamal_image(Gamal_i, Gamal_j, 2) * 2, 255);
            }
            else if (Gamal_choice1 == 'b')
            {
                Gamal_image(Gamal_i, Gamal_j, 0) = Gamal_image(Gamal_i, Gamal_j, 0) / 2;
                Gamal_image(Gamal_i, Gamal_j, 1) = Gamal_image(Gamal_i, Gamal_j, 1) / 2;
                Gamal_image(Gamal_i, Gamal_j, 2) = Gamal_image(Gamal_i, Gamal_j, 2) / 2;
            }
        }
    }
    //    cout << "Do you want to save changes in the same image?\n"
    //         << "a)Yes\n"
    //         << "b)No\n";
    //    cin >> Gamal_choice2;
    //    while (Gamal_choice2 != 'a' && Gamal_choice2 != 'b')
    //    {
    //        cout << RED << "invalid choice\n" << RESET_COLOR;
    //        cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
    //             << "a)Yes\n"
    //             << "b)No\n";
    //        cin >> Gamal_choice2;
    //    }
    //    if (Gamal_choice2 == 'a')
    //    {
    //        Gamal_image.saveImage(Gamal_filename);
    //        system(Gamal_filename.c_str());
    //    }
    //    else if (Gamal_choice2 == 'b')
    //    {
    //        cout << "Pls enter image name to store new image\n";
    //        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    //        cin >> Gamal_filename;
    Gamal_image.saveImage("saved.jpg");
    //        system(Gamal_filename.c_str());
    //    }
    unsaved_image = true;
    return Gamal_image;
}
//=====================================================================================================================
Image Black_and_White(string Mustafa_filename) {

    // Take image.
    Image Mustafa_image(Mustafa_filename);

    for (int i = 0; i < Mustafa_image.width; ++i) {
        for (int j = 0; j < Mustafa_image.height; ++j) {
            unsigned  int Mustafa_average = 0; // Initialize average value

            for (int k = 0; k < 3; ++k) {
                // Take the average to know if the color of the pixel is dark of light.
                Mustafa_average += Mustafa_image(i, j, k); // Accumulate pixel values
            }

            Mustafa_average /= 3; // Calculate average

            for (int k = 0; k < 3; ++k) {
                // change every light pixel to wight.
                if (Mustafa_average > 127) {
                    Mustafa_image(i, j, k) = 255;
                }
                // change every dark pixel to black.
                else if (Mustafa_average <= 127) {
                    Mustafa_image(i, j, k) = 0;
                }
            }
        }
    }
    Mustafa_image.saveImage("saved.jpg");
    return Mustafa_image;
}
//====================================================================================================================
//Image vertical_flip(string Mustafa_filename) {
////    string Mustafa_filename;
////    Mustafa_filename = get_image(SYSTEM_COLOR + "Please,enter the name of the image you want to flip:" + RESET_COLOR);
//    // take from the user the image name.
//    Image Mustafa_image(Mustafa_filename);
//    // make an image with the same width and height.
//    Image Mustafa_image2(Mustafa_image.width, Mustafa_image.height);
//
//    for (int i = 0; i < Mustafa_image2.width; ++i) {
//        for (int j = 0; j < Mustafa_image2.height; ++j) {
//            for (int k = 0; k < 3; ++k) {
//                // swap every pixel with its opposite in the height.
//                Mustafa_image2(i, (j), k) = Mustafa_image(i, (Mustafa_image.height - j - 1), k); // Accumulate pixel values
//            }
//        }
//    }
////    cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;
////    // save the new image.
////    cin >> Mustafa_filename;
////    Mustafa_image2.saveImage(Mustafa_filename);
////    system(Mustafa_filename.c_str());
//
//    return 0;
//}
//
//Image horizontal_flip(string Mustafa_filename) {
////    string Mustafa_filename;
////    cout << SYSTEM_COLOR << "Please,enter the name of the image you want to flip:" << RESET_COLOR;
////    cin >> Mustafa_filename;
//    // take from the user the image name.
//    Image Mustafa_image(Mustafa_filename);
//    // make an image with the same width and height.
//    Image Mustafa_image2(Mustafa_image.width, Mustafa_image.height);
//
//    for (int i = 0; i < Mustafa_image2.width; ++i) {
//        for (int j = 0; j < Mustafa_image2.height; ++j) {
//            for (int k = 0; k < 3; ++k) {
//                // swap every pixel with its opposite in the width.
//                Mustafa_image2(i, j, k) = Mustafa_image(Mustafa_image.width - i - 1, j, k); // Accumulate pixel values
//            }
//
//        }
//    }

//    cout << SYSTEM_COLOR << "\nPlease, enter the new image name to be stored \nand specify extension .jpg, .bmp, .png, .tga:" << RESET_COLOR << endl;
//    cin >> Mustafa_filename;
//    Mustafa_image2.saveImage(Mustafa_filename);
//    system(Mustafa_filename.c_str());

//    return 0;
//}
Image Flip_Image(string Mustafa_filename) {
    string choice;
    // take from the user the image name.
    Image Mustafa_image(Mustafa_filename);
    // make an image with the same width and height.
    Image Mustafa_image2(Mustafa_image.width, Mustafa_image.height);
    // know if the user want to continue by doing other operations or not.
    while (true) {
        cout << SYSTEM_COLOR << "What kind of flip do you want: \n1)Vertical flip\n2)Horizontal flip\n3)Exit" << RESET_COLOR << endl;
        cin >> choice;
        if (choice == "1") {
            for (int i = 0; i < Mustafa_image2.width; ++i) {
                for (int j = 0; j < Mustafa_image2.height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        // swap every pixel with its opposite in the height.
                        Mustafa_image2(i, (j), k) = Mustafa_image(i, (Mustafa_image.height - j - 1), k); // Accumulate pixel values
                    }
                }
            }
            Mustafa_image2.saveImage("saved.jpg");
            break;
        }
        else if (choice == "2") {
            for (int i = 0; i < Mustafa_image2.width; ++i) {
                for (int j = 0; j < Mustafa_image2.height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        // swap every pixel with its opposite in the width.
                        Mustafa_image2(i, j, k) = Mustafa_image(Mustafa_image.width - i - 1, j, k); // Accumulate pixel values
                    }

                }
            }
            Mustafa_image2.saveImage("saved.jpg");
            break;
        }
        else if (choice == "3") {
            break;
        }
        else { cout << RED << "Please, enter a valid input." << RESET_COLOR; }
    }
    return Mustafa_image;
}
//======================================================================================================================
Image Crop_Images(string Mustafa_filename) {
    //    string Mustafa_filename;
    int width, height, x, y;
    // take from the user the image name.
//    Mustafa_filename = get_image(SYSTEM_COLOR + "Please, enter the image name to crop it:\n" + RESET_COLOR);
    Image Mustafa_image(Mustafa_filename);
    while (true) {
        // take from the user the (X) coordinates.
        cout << SYSTEM_COLOR << "Please, enter the first coordinates of the starting point to crop the image (x):" << RESET_COLOR << endl;
        cin >> x;
        // take from the user the (Y) coordinates
        cout << SYSTEM_COLOR << "Please, enter the second coordinates of the starting point to crop the image (y):" << RESET_COLOR << endl;
        cin >> y;
        // take from the user the image width.
        cout << SYSTEM_COLOR << "Please, enter the colored image width:" << RESET_COLOR << endl;
        cin >> width;
        // take from the user the image height.
        cout << SYSTEM_COLOR << "Please, enter the colored image height:" << RESET_COLOR << endl;
        cin >> height;
        // check if the dimensions is correct
        if ((x + width > Mustafa_image.width) && (y + height > Mustafa_image.height)) {
            cout << RED << "The dimensions is not valid to crop,please try again." << RESET_COLOR << endl;
        }
        else { break; }
    }
    Image Mustafa_image2(width, height);
    for (int i = x; i < x + Mustafa_image2.width; ++i) {
        for (int j = y; j < y + Mustafa_image2.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                // copy the selected peace of the image to the new one.
                Mustafa_image2(i - x, j - y, k) = Mustafa_image(i, j, k); // Accumulate pixel values
            }
        }
    }
    Mustafa_image2.saveImage("saved.jpg");
    return Mustafa_image;
}