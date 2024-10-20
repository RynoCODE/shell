
# Function to display the menu and get the user's choice
show_menu() {
    echo "Simple Shell Calculator"
    echo "========================"
    echo "1. Addition"
    echo "2. Subtraction"
    echo "3. Multiplication"
    echo "4. Division"
    echo "5. Exit"
    echo "Enter your choice: "
}

# Main calculator logic
while true
do
    show_menu
    read choice
    
    # Exit the loop if the user chooses 5
    if [ $choice -eq 5 ]; then
        echo "Exiting..."
        break
    fi
    
    # Read two numbers from the user
    echo "Enter first number: "
    read num1
    echo "Enter second number: "
    read num2
    
    # Perform the selected operation
    case $choice in
        1) # Addition
            result=$((num1 + num2))
            echo "Result: $num1 + $num2 = $result"
            ;;
        2) # Subtraction
            result=$((num1 - num2))
            echo "Result: $num1 - $num2 = $result"
            ;;
        3) # Multiplication
            result=$((num1 * num2))
            echo "Result: $num1 * $num2 = $result"
            ;;
        4) # Division
            if [ $num2 -ne 0 ]; then
                result=$((num1 / num2))
                echo "Result: $num1 / $num2 = $result"
            else
                echo "Error: Division by zero is not allowed!"
            fi
            ;;
        *) # Invalid choice
            echo "Invalid choice! Please select a valid option."
            ;;
    esac
    echo ""
done
