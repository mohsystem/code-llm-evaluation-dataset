import os
from Crypto.PublicKey import RSA

def generate_rsa_keys():
    key = RSA.generate(2048)
    private_key = key.export_key()
    public_key = key.publickey().export_key()
    
    with open('rsa_private.pem', 'wb') as pvt_file:
        pvt_file.write(private_key)
        
    with open('rsa_public.pem', 'wb') as pub_file:
        pub_file.write(public_key)

def main():
    if not os.path.exists('rsa_private.pem') or not os.path.exists('rsa_public.pem'):
        generate_rsa_keys()
    print("Keys are generated and stored as rsa_private.pem and rsa_public.pem")

if __name__ == "__main__":
    main()