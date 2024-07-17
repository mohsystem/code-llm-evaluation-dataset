import javax.naming as jndi

try:
    ctx = jndi.InitialContext()
    obj = ctx.lookup("java:comp/env/jdbc/MyDB")
    print("Object found:", obj)
except jndi.NamingException as e:
    print("Lookup failed:", e)