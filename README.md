# 📂 **Make**

### 📝 **Presentation**

The "Make" program is a simple tool that allows the creation of directories and files with specific extensions and names based on user input. The code is well-structured and uses clear indentation with consistent naming conventions to improve readability.

- The program uses a `struct` to hold various boolean flags that define whether a directory, file, or extension should be created.
- Functions are organized for initialization, logic processing, and output.
- A debug mode is available to provide more information on the execution process.

The indentation follows a 4-space rule, making the code easy to read. Boolean variables use descriptive names like `dir`, `file`, and `debug` for clarity.

---

### 🚀 **Usage Guide**

This program allows you to create directories or files using the following arguments:

1. **Arguments:**
   - `dir`: Create a directory.
   - `file`: Create a file.
   - `-e <extension>`: Specify a file extension (e.g., `.txt`, `.c`).
   - `-n <name>`: Set a custom name for the directory or file.
   - `-debug` or `-d`: Enable debug mode to print additional information.

2. **Example Commands:**
   - `./make dir -n myFolder`: Creates a directory named "myFolder".
   - `./make file -n myFile -e .txt`: Creates a file named "myFile.txt".
   - `./make file -debug`: Runs in debug mode, showing more information.

3. **Debug Mode:**
   - If the `-debug` or `-d` flag is used, the program will print the internal states and actions, such as the directory and file names being created, as well as any errors encountered during execution.

---

### 📄 **License**

This project is licensed under the GNU General Public License v3.0 (GPL-3.0). You can freely use, modify, and distribute this software as long as you comply with the terms of the GPL-3.0 license.
