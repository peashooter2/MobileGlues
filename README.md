# MobileGlues

**MobileGlues**, which stands for "(on) Mobile, GL uses ES", is a GL implementation running on top of host OpenGL ES 3.1, with running Minecraft Java Edition in mind.

# About this branch

This branch integrates gl4es to support OpenGL fixed-function pipeline features.

**Feature: Capability to support Minecraft 1.16.5 and 1.4.7.**

# License

MobileGlues is licensed under **GNU LGPL-2.1 License**.

Please see [LICENSE](https://github.com/MobileGL-Dev/MobileGlues/blob/main/LICENSE).

# Third party components

**SPIRV-Cross** by **KhronosGroup**: [github](https://github.com/KhronosGroup/SPIRV-Cross)

**glslang** by **KhronosGroup**: [github](https://github.com/KhronosGroup/glslang)

**GlslOptimizerV2** by **aiekick**: [github](https://github.com/aiekick/GlslOptimizerV2)

**cJSON** by **DaveGamble**: [github](https://github.com/DaveGamble/cJSON)

# Third-Party Component Code Referenced and Borrowed

**gl4es** by **ptitSeb**: [github](https://github.com/ptitSeb/gl4es):

This project retains all state machines within gl4es and preserves every OpenGL front-end call directed to these state machines, thereby offering comprehensive FPE emulation support. Please note that gl4es is not involved in rendering aspects outside of FPE in this project.