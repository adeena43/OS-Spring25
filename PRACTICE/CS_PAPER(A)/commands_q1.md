**Linux System Administration Tasks**

### 1. **Create Directories and List Contents**  
```bash
cd ~/Desktop                     # Navigate to the Desktop
mkdir -p "Project Files"/{Docs,Scripts,Backups}  # Create main directory with subdirectories
ls -R "Project Files"            # List the contents recursively to verify creation
```
**Description:** This creates a `Project Files` directory with `Docs`, `Scripts`, and `Backups` subdirectories, then verifies them.  

---

### 2. **Rename, Move, Create, and Edit Files**  
```bash
mv oldfile.txt newfile.txt       # Rename oldfile.txt to newfile.txt
mv newfile.txt "Project Files/Docs/" # Move the renamed file to the Docs directory
touch "Project Files/Scripts/script.sh"  # Create an empty file in Scripts
nano "Project Files/Scripts/script.sh"  # Edit the file using nano (or use vi, vim)
```
**Description:** Renames `oldfile.txt`, moves it, creates an empty file in `Scripts`, and opens it for editing.  

---

### 3. **Change Ownership and Modify Permissions**  
```bash
chown user:user "Project Files" -R   # Change ownership of all files to a specific user
chmod u+x "Project Files/Scripts/"*  # Allow only the owner to execute files in Scripts
```
**Description:** Changes ownership recursively to a specific user and grants execution permission only to the owner.  

---

### 4. **Add a New User, Set a Password, and Change Ownership**  
```bash
sudo useradd newuser               # Add a new user
sudo passwd newuser                # Set password for newuser
sudo chown newuser:newuser "Project Files/Docs/newfile.txt"  # Change file ownership
```
**Description:** Adds a new system user, sets a password, and assigns ownership of a file.  

---

### 5. **Monitor System Performance**  
```bash
top                                # Display real-time system performance
free -h                            # Check memory usage
grep "searchword" "Project Files/Docs/newfile.txt"  # Search for a specific word in a text file
```
**Description:** `top` monitors system performance, `free -h` checks memory, and `grep` searches for a word in a file.  

---

### 6. **Find, Remove, and Compress Files**  
```bash
find "Project Files/Scripts/" -name "*.sh"  # Find all .sh files in Scripts
rm "Project Files/Backups/unwantedfile.txt" # Remove an unnecessary file from Backups
zip -r Project_Files.zip "Project Files/"  # Compress Project Files into ZIP format
```
**Description:** Searches for shell scripts, removes a file, and compresses the entire directory.  

---

### 7. **Set Date and Modify Timestamp**  
```bash
sudo date -s "2025-03-11 10:30:00"  # Set system date and time
touch -t 202503110930 "Project Files/Docs/newfile.txt"  # Change file timestamp
```
**Description:** Sets the system date and modifies the timestamp of a file.  

---

### 8. **Search Inside Files and Find Scripts (Again)**  
```bash
grep "specificword" "Project Files/Docs/textfile.txt"  # Search for a word in Docs
find "Project Files/Scripts/" -name "*.sh"  # Find all shell scripts in Scripts
```
**Description:** Searches for a word inside a text file and locates all `.sh` files in the Scripts directory.  

---

This set of commands will help maintain and optimize the Linux-based system efficiently. 🚀
