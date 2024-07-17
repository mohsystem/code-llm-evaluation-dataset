
import sys

def check_access(user_role, resource):
    access_matrix = {
        \'admin\': [\'server\', \'database\', \'network\'],
        \'developer\': [\'database\', \'codebase\'],
        \'tester\': [\'codebase\', \'testbed\'],
        \'user\': [\'application\']
    }
    
    if user_role in access_matrix and resource in access_matrix[user_role]:
        return True
    return False

def main():
    user_role = input("Enter your role: ").lower()
    resource = input("Enter the resource you want to access: ").lower()
    
    if check_access(user_role, resource):
        print(f"Access granted to {resource}")
    else:
        print("Access denied")

if __name__ == "__main__":
    main()
