#include <iostream>
using namespace std;

const int row = 6;
const int col = 6;

// Function declarations
void showmore();
void book_seat(int movie[row][col]);
void cancel(int movie[row][col]);
void display(int movie[row][col]);
void countticket(int movie[row][col]);
void totalprice(int movie[row][col]);

// Menu display
void showmore() {
    cout << "\nMovie Booking System" << endl;
    cout << "1. Book Ticket" << endl;
    cout << "2. Cancel Ticket" << endl;
    cout << "3. Display Seats" << endl;
    cout << "4. Count Booked Seats" << endl;
    cout << "5. Total Price" << endl;
    cout << "6. Exit" << endl;
}

// Book a seat
void book_seat(int movie[row][col]) {
    int r, c;
    cout << "Enter row and column for seat booking: ";
    cin >> r >> c;

    if (r >= 0 && r < row && c >= 0 && c < col) {
        if (movie[r][c] == 0) {
            movie[r][c] = 1;
            string seatType;
            int price = 0;

            if (r == 0 || r == 1) {
                seatType = "Diamond";
                price = 500;
            } else if (r == 2 || r == 3) {
                seatType = "Gold";
                price = 350;
            } else {
                seatType = "Silver";
                price = 200;
            }

            cout << "You have selected a " << seatType << " seat. Price: Rs. " << price << endl;
            cout << "Your seat is booked!" << endl;
        } else {
            cout << "Sorry, that seat is already booked!" << endl;
        }
    } else {
        cout << "Invalid seat position!" << endl;
    }
}

// Cancel a booking
void cancel(int movie[row][col]) {
    int r, c;
    cout << "Enter row and column to cancel booking: ";
    cin >> r >> c;

    if (r >= 0 && r < row && c >= 0 && c < col) {
        if (movie[r][c] == 1) {
            movie[r][c] = 0;
            cout << "Your booking has been canceled." << endl;
        } else {
            cout << "That seat was not booked." << endl;
        }
    } else {
        cout << "Invalid seat position!" << endl;
    }
}

// Display seat layout
void display(int movie[row][col]) {
    cout << "\nSeat Layout (0 = Available, 1 = Booked):" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << movie[i][j] << " ";
        }
        cout << endl;
    }
}

// Count booked seats
void countticket(int movie[row][col]) {
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (movie[i][j] == 1) {
                count++;
            }
        }
    }
    cout << "Total booked seats: " << count << endl;
}

// Calculate total price
void totalprice(int movie[row][col]) {
    int total = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (movie[i][j] == 1) {
                if (i == 0 || i == 1) {
                    total += 500; // Diamond
                } else if (i == 2 || i == 3) {
                    total += 350; // Gold
                } else {
                    total += 200; // Silver
                }
            }
        }
    }
    cout << "Total price: Rs. " << total << endl;
    cout << "Total price with GST (18%): Rs. " << (0.18 * total + total) << endl;
}

// Main function
int main() {
    int choice;
    int movie[row][col] = {0};

    do {
        showmore();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                book_seat(movie);
                break;
            case 2:
                cancel(movie);
                break;
            case 3:
                display(movie);
                break;
            case 4:
                countticket(movie);
                break;
            case 5:
                totalprice(movie);
                break;
            case 6:
                cout << "Thank you! Visit again." << endl;
                break;
            default:
                cout << "Wrong choice. Please try again." << endl;
        }
        cout << endl;
    } while (choice != 6);

    return 0;
}

/*

Movie Booking System
1. Book Ticket
2. Cancel Ticket
3. Display Seats
4. Count Booked Seats
5. Total Price
6. Exit
Enter your choice: 1
Enter row and column for seat booking: 1
1
You have selected a Diamond seat. Price: Rs. 500
Your seat is booked!


Movie Booking System
1. Book Ticket
2. Cancel Ticket
3. Display Seats
4. Count Booked Seats
5. Total Price
6. Exit
Enter your choice: 1
Enter row and column for seat booking: 2
1
You have selected a Gold seat. Price: Rs. 350
Your seat is booked!


Movie Booking System
1. Book Ticket
2. Cancel Ticket
3. Display Seats
4. Count Booked Seats
5. Total Price
6. Exit
Enter your choice: 1
Enter row and column for seat booking: 3
1
You have selected a Gold seat. Price: Rs. 350
Your seat is booked!


Movie Booking System
1. Book Ticket
2. Cancel Ticket
3. Display Seats
4. Count Booked Seats
5. Total Price
6. Exit
Enter your choice: 1
Enter row and column for seat booking: 3
2
You have selected a Gold seat. Price: Rs. 350
Your seat is booked!


Movie Booking System
1. Book Ticket
2. Cancel Ticket
3. Display Seats
4. Count Booked Seats
5. Total Price
6. Exit
Enter your choice: 2
Enter row and column to cancel booking: 3
2
Your booking has been canceled.


Movie Booking System
1. Book Ticket
2. Cancel Ticket
3. Display Seats
4. Count Booked Seats
5. Total Price
6. Exit
Enter your choice: 3

Seat Layout (0 = Available, 1 = Booked):
0 0 0 0 0 0
0 1 0 0 0 0
0 1 0 0 0 0
0 1 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0


Movie Booking System
1. Book Ticket
2. Cancel Ticket
3. Display Seats
4. Count Booked Seats
5. Total Price
6. Exit
Enter your choice: 4
Total booked seats: 3


Movie Booking System
1. Book Ticket
2. Cancel Ticket
3. Display Seats
4. Count Booked Seats
5. Total Price
6. Exit
Enter your choice: 5
Total price: Rs. 1200
Total price with GST (18%): Rs. 1416


Movie Booking System
1. Book Ticket
2. Cancel Ticket
3. Display Seats
4. Count Booked Seats
5. Total Price
6. Exit
Enter your choice: 6
Thank you! Visit again.
*/
