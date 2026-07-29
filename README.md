# 📚 Library Management System (C++)

A simple **Library Management System** built using **C++** that demonstrates the use of fundamental programming concepts such as structures, arrays, file handling, sorting, searching, exception handling, and modular programming.

This project was created as a practice project to strengthen problem-solving skills and object-oriented thinking while working with real-world scenarios.

---

## 🚀 Features

### 📖 Book Management

* Add new books to the library.
* Prevent duplicate book names.
* Search books using a prefix.
* Display books sorted by:

  * Book Name
  * Book ID

### 👤 User Management

* Add new users.
* Display all registered users.

### 🔄 Borrow & Return System

* Borrow books by book name.
* Automatically decrease available quantity.
* Return borrowed books.
* Automatically increase available quantity.
* Display users who borrowed a specific book.

### 💾 File Persistence

The application stores data locally using text files:

* **books.txt** → Stores all books.
* **Users.txt** → Stores all users.

Data is automatically loaded when the program starts and saved after updates.

---

# 🛠 Technologies Used

* C++
* Structures (struct)
* Arrays
* Functions
* File Handling (`fstream`)
* Exception Handling (`try/catch`)
* Bubble Sort
* Linear Search

---

# 📂 Project Structure

```
Library-Management-System/
│
├── main.cpp
├── books.txt
├── Users.txt
└── README.md
```

---

# 📋 Menu

```
1. Add Book
2. Search Book by Prefix
3. Borrow Book
4. List Books by Name
5. List Books by ID
6. Add User
7. Return Book
8. Print All Users
9. Print Users Who Borrowed a Book
0. Exit
```

---

# 💡 Concepts Practiced

This project helped me practice:

* Modular programming
* Data organisation using structures
* Input validation
* Exception handling
* Searching algorithms
* Sorting algorithms
* File input/output
* Simple inventory management
* Basic library system logic

---

# 📸 Example Workflow

1. Add a new book.
2. Add a new user.
3. Borrow a book.
4. Quantity decreases automatically.
5. Return the book.
6. Quantity is restored.
7. Check which users borrowed a specific book.

---

# 🔮 Future Improvements

* Replace arrays with STL vectors.
* Store users' borrowed books in separate files.
* Search books by ID.
* Delete and update books/users.
* Use classes instead of structs.
* Move the project to an SQL database.
* Build a graphical user interface (GUI).
* Implement login and administrator permissions.

---

# 🎯 Learning Outcome

This project strengthened my understanding of core C++ programming concepts and showed me how to organise a medium-sized console application. It also provided practical experience with file handling, data management, and implementing real-world business logic.

---

## ⭐ If you like this project

Feel free to give it a **Star ⭐** on GitHub and share your feedback or suggestions!
