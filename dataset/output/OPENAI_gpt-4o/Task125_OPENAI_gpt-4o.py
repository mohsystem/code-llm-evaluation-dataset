def access_resource(user):
    resources = {
        "admin": "Access to administrative resources granted.",
        "user": "Access to user resources granted.",
        "guest": "Access to guest resources granted."
    }
    return resources.get(user, "No resources available for this user role")

if __name__ == "__main__":
    user_role = input("Enter user role (admin/user/guest): ").strip().lower()
    print(access_resource(user_role))