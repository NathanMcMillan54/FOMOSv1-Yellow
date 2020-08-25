import os
import time

print("Compiling...")
os.system('sh compile.sh')
os.system('./lightTheme')
print("Deleting Filse...")
os.system('rm -rf settings')
os.system('rm -rf calculator')
print("Compiling again...")
os.system('sh compile.sh')
time.sleep(1)
os.system('./settings')
