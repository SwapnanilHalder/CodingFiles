import subprocess
import sys

def install(package):
    subprocess.check_call([sys.executable, "-m", "pip", "install", package])
    reqs = subprocess.check_output([sys.executable, '-m', 'pip',
    'freeze'])
    installed_packages = [r.decode().split('==')[0] for r in reqs.split()]
    
    print(installed_packages)
install('sympy')