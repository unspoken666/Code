#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#BatchInstall.py
import os
libs = {"numpy","matplotlib","pillow","sklearn","requests","jieba","beautifulsoup4","wheel","networkx","sympy",        "pyinstaller","djanggo","flask","werobot","pyqt5","pandas","pyopeng1","pypdf2","docopt","pygame"}
try:
    for lib in libs:
        os.system("pip install" + lib)
    print("Successful")
except:
    print("Failed Somehow")

