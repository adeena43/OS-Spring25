while true;
do
    echo -e "CUTSOM OS MENU\n"
    echo "1. Create a text file"
    echo "2. Open a text file for editing"
    echo "3. Change file permissions to all"
    echo "4. Exit"
    read -p "Enter you choice: " choice

    case $choice in
        1) 
            read -p "Enter the file name to create" filename
            touch $filename
            echo "Created file $filename successfully"
            ;;

        2) 
            read -p "Enter name of the file to edit" filename
            nano $filename
            ;;

        3) 
            read -p "Enter the nae of the file to change permissions of" fileame
            chmod $filename 777
            echo "Permissions changed to all successfully"
            ;;

        4)
            echo "Exiting"
            break
            ;;
        
        *)
            echo "Invalid choice"
            ;;
    esac
done
