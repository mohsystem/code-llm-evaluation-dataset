input_str = input("Enter user role (admin/user/guest): ").strip().lower()

if input_str == "admin":
    print("Redirecting to admin page...")
elif input_str == "user":
    print("Redirecting to user page...")
elif input_str == "guest":
    print("Redirecting to guest page...")
else:
    print("Invalid role!")