import os

print("Compiling...")
os.system('sh compile.sh')
os.system('./lightTheme')
print("Deleting Filse...")
os.system('rm -rf settings')
os.system('rm -rf calculator')
print("Compiling again...")
os.system('sh compile.sh')
os.system('./settings')
