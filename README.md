# Student Record Management System

### Project Context
This application was developed as a technical capstone project to demonstrate mastery of fundamental C programming concepts. It serves as proof-of-concept for building persistent data systems without relying on high-level libraries.

The primary engineering goals were:
* **Manual Memory Management:** Handling data flow between Stack memory and Disk storage.
* **File Persistence Patterns:** Implementing CRUD (Create, Read) operations using standard I/O(`stdio.h`).
* **Algorithm Implementation:** Writing raw logic for data analysis (Linear Search) rather than using pre-built sorting functions.

---

### Technical Concepts Demonstrated
* **Persistent Storage:** Implements `fopen`, `fprintf`, and `fscanf` to save data between program sessions.
* **Structured Data Schema:** Uses `struct` to define a complex data type (`Student`) holding mixed primitives (`char[]` and `int`).
* **Algorithmic Logic:** Implements a linear search algorithm to identify maximum value (Top Student) in a single pass.
* **Input Handling:** Management of the `stdin` buffer using `getchar()` to prevent input skipping bugs.

### Usage
The program operates via a numbered menu loop:
1. **Add Student:** Prompts user for Name, ID, and Grade, then appends the record to `classdata.txt`.
2. **View All:** Parses the file line by line and formats the raw data into a readable ASCII table.
3. **Find Top Student:** Iterates through the entire dataset to identify and display the details of the highest performing student.

### Acknowledged Limitations
* **Name Spacing:** The system currently uses `fscanf` for data parsing, which delimits input by whitespace. Therefore names must be single words (For Example: use `Eren_Jaeger` instead of `Eren Jaeger`). Future updates will implement `fgets` for robust string parsing.
* **ID Collision:** There is currently no validation check for duplicate Student IDs; the system assumes unique entry.
