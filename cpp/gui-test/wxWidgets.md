## Quick CMake + wxWidgets project template

### Files (project root)

- CMakeLists.txt
- src/main.cpp
- build/ (created at build time)

### CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.16)
project(wx_demo LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(wx_demo src/main.cpp)
target_include_directories(wx_demo PUBLIC ${wxWidgets_INCLUDE_DIRS})
target_link_libraries(wx_demo ${wxWidgets_LIBRARIES})
```

### src/main.cpp (minimal example)

```cpp
#include <wx/wx.h>
class MyApp : public wxApp {
  bool OnInit() override {
    wxFrame* f = new wxFrame(nullptr, wxID_ANY, "wxDemo", wxDefaultPosition, {400,200});
    f->Show();
    return true;
  }
};
wxIMPLEMENT_APP(MyApp);
```

### Build & run (repeat each time)

1. Create build dir and run CMake:

```bash
mkdir -p build
cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
```

2. Build:

```bash
cmake --build .
```

3. Run:

```bash
./wx_demo
```

### Notes / quick fixes

- If wx-config flags missing, ensure wxwidgets installed (Arch: sudo pacman -S wxwidgets-gtk3).
- If editor needs include paths, use the generated build/compile_commands.json (symlink to project root if necessary):

```bash
ln -sf build/compile_commands.json compile_commands.json
```

- To see exact compile flags: wx-config --cxxflags --libs
