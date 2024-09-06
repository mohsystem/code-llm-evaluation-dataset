# Python code for password reset functionality

def reset_password(current_password, new_password, confirm_password):
    # For simplicity, let's assume the current password is 'oldpassword'
    if current_password != 'oldpassword':
        return "Current password is incorrect."
    elif new_password != confirm_password:
        return "New password and confirm password do not match."
    else:
        # In a real-world application, you would update the password here
        return "Password reset successful."

# Test the function
print(reset_password('oldpassword', 'newpassword', 'newpassword'))