import jndi

# Set up JNDI environment
env = {
    "java.naming.factory.initial": "com.sun.jndi.dns.DnsContextFactory",
    "java.naming.provider.url": "dns://localhost"
}

# Perform JNDI lookup
try:
    obj = jndi.lookup("example.com/MyObject", env=env)
    print(f"Retrieved object: {obj}")
except Exception as e:
    print(f"Error during JNDI lookup: {e}")