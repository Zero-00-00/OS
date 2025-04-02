clear

# Function to check if a login name is valid
is_valid_login() {
    if id "$1" &>/dev/null
    then
        return 0
    else
        return 1
    fi
}

# Prompt the user for a login name
read -p "Enter login name: " login_name

# Check if the login name is valid
if is_valid_login "$login_name"; then
    echo "Login name '$login_name' is valid."
else
    echo "Login name '$login_name' is not valid."
fi
