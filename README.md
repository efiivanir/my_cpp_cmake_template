# my_cpp_cmake_template
**Personal Template For C++ Cmake Projects**
This is an on going project, I use this template gor my C++ projects, add features according to my knoledge.

## Use

Add this bash function into your .bashrc file, Them run this function with project name

```shell
function cm-create-project {

    cmds=(
      'gh'
      'perl'
    )
    for cmd in "${cmds[@]}"; do
        if ! [ -x "$(command -v $cmd)" ]; then
            echo "Error: $cmd is not installed." >&2
            return 1
        fi
    done

    if [ $# -ne 1 ]; then
       echo "Usage: cm-create-project PROJECT_NAME"
       return 1
    fi

    prj=$1
    if test -d ${prj}; then
        echo "Err: $prj exists. Please remove it, Or change project name."
        return 1
    fi
    echo "Create cmake project ${prj}, based on my_cpp_cmake_template"
    gh repo clone efiivanir/my_cpp_cmake_template ./${prj}
    perl -p -i -e "s/MY_PROJECT Please_Change/MY_PROJECT $prj/" ./${prj}/CMakeLists.txt

}

```
