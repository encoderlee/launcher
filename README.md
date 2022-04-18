# launcher
simple launcher for python application packaged by PyInstaller

1. pack python application by PyInstaller with param -D
2. rename the directory to 'dist'
3. copy launcher.exe with 'dist'
4. if your app name is gui.exe in 'dist', rename launcher.exe to gui.exe


一个简单的启动器，用于启动PyInstaller打包的python程序

避免在打包出的dist目录中一堆杂乱无章的文件里寻找.exe文件

1. 用 -D 参数打包python程序为一个目录
2. 把目录名修改为 'dist'
3. 把luncher.exe拷贝到'dist'目录同级
4. 如果'dist'里打包后的python程序名为gui.exe，则把luncher.exe重命名为gui.exe