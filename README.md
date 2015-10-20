# prjPluginFramework

Goal of this project is to create a flexable and dynamic plugin system using C++.

Interfaces for the plugins are to be created virtually in memory by reading a coresponding XML configuration file.


|------------------|            |------------------|            |-----------------|
| PluginLoader.exe |  --------> | DummyPlugin.conf |  --------> | DummyPlugin.dll |
|------------------|            |------------------|            |-----------------|

1.) PluginLoader.exe scans it current directory for any *.conf files.
2.) PluginLoader.exe reads available .conf files, and creates a virtual interface in memory.
3.) PluginLoader.exe uses its virtual interface to call functions inside DummyPlugin.dll
