#!/bin/bash
# ----------------------------
# Script to rename the project
# ----------------------------

# Autodetect the git repository
PROJECT_GIT_REPO_AUTO=$(git remote get-url origin 2> /dev/null)
if echo "${PROJECT_GIT_REPO_AUTO}" | grep -o "^git@.*:" > /dev/null 2>&1; then
    # Convert to https
    PROJECT_GIT_REPO_AUTO_=$(echo "${PROJECT_GIT_REPO_AUTO}" | cut -d'@' -f 2)
    PROJECT_GIT_REPO_AUTO_HOST=$(echo "${PROJECT_GIT_REPO_AUTO_}" | cut -d':' -f 1)
    PROJECT_GIT_REPO_AUTO_PATH=$(echo "${PROJECT_GIT_REPO_AUTO_}" | cut -d':' -f 2)
    PROJECT_GIT_REPO_AUTO="https://${PROJECT_GIT_REPO_AUTO_HOST}/${PROJECT_GIT_REPO_AUTO_PATH}"
fi

# Specify the git repository
echo "Please enter the git repository path (No semicolons):"
echo -e "Press enter to keep the autodetected git repository:\n\e[32m${PROJECT_GIT_REPO_AUTO}\e[0m"
read PROJECT_GIT_REPO
if [ -z "$PROJECT_GIT_REPO" ]; then
    PROJECT_GIT_REPO="${PROJECT_GIT_REPO_AUTO}"
fi
echo


# Autodetect the project and executable name
PROJECT_EXECUTABLE_NAME_AUTO="$(echo "${PROJECT_GIT_REPO}" | rev | cut -d'/' -f 1 | rev | cut -d'.' -f 1)"
PROJECT_NAME_AUTO=$(echo "${PROJECT_EXECUTABLE_NAME_AUTO}" | sed 's/-/ /g')
PROJECT_NAME_AUTO="${PROJECT_NAME_AUTO^}"

# Specify the project name
echo "Please enter the project name (No slashes '/'):"
echo -e "Press enter to keep the autodetected project name: \e[32m'${PROJECT_NAME_AUTO}'\e[0m"
read PROJECT_NAME
if [ -z "$PROJECT_NAME" ]; then
    PROJECT_NAME="${PROJECT_NAME_AUTO}"
fi
echo

# Specify the executable name
echo "Please enter the project executable name (No spaces, no slashes '/')"
echo -e "Press enter to keep the autodetected executable name: \e[32m'${PROJECT_EXECUTABLE_NAME_AUTO}'\e[0m"
read PROJECT_EXECUTABLE_NAME
if [ -z "$PROJECT_EXECUTABLE_NAME" ]; then
    PROJECT_EXECUTABLE_NAME="${PROJECT_EXECUTABLE_NAME_AUTO}"
fi
echo


# Display a summary for confirmation
echo
echo "This script will rename your project, like the following:"
echo -e "Project git repository:  \e[32m'${PROJECT_GIT_REPO}'\e[0m"
echo -e "Project name:            \e[32m'${PROJECT_NAME}'\e[0m"
echo -e "Project executable name: \e[32m'${PROJECT_EXECUTABLE_NAME}'\e[0m"
echo
echo -e "\e[31mDo you confirm your modifications ? [y/N]\e[0m"
read RENAME_PROJECT
if [ -n "$RENAME_PROJECT" ] && [ "$(echo "$RENAME_PROJECT" | tr a-z A-Z)" = "Y" ]; then
    sed -i "s/SDL2_image sample/${PROJECT_NAME}/g" README.md rename_project.sh
    sed -i "s/sdl2-image-sample/${PROJECT_EXECUTABLE_NAME}/g" README.md IDE_USAGE.md CMakeLists.txt rename_project.sh
    sed -i "s;https://gitlab.com/aminosbh/sdl2-image-sample.git;${PROJECT_GIT_REPO};g" README.md rename_project.sh
    echo -e "\e[32mThe project was successfully renamed\e[0m"
else
    echo -e "\e[33mOperation aborted\e[0m"
fi

