# prjPluginFramework

Goal of this project is to create a flexable and dynamic plugin system using C++.

Interfaces for the plugins are to be created virtually in memory by reading a coresponding XML configuration file.

1.) PluginLoader.exe scans it current directory for any *.conf files.

2.) PluginLoader.exe finds a file names DummyPlugin.conf.

3.) PluginLoader.exe reads DummyPlugin.conf, and creates a virtual interface in memory.

4.) PluginLoader.exe uses its virtual interface to call functions inside DummyPlugin.dll.

![alt tag](http://s18.postimg.org/4gjcby3a1/Diagram.png)
