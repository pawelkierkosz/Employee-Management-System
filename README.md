[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/p1G4V0f-)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=12432708&assignment_repo_type=AssignmentRepo)
<header>

<!--
  <<< Author notes: Course header >>>
  Read <https://skills.github.com/quickstart> for more information about how to build courses using this template.
  Include a 1280×640 image, course name in sentence case, and a concise description in emphasis.
  In your repository settings: enable template repository, add your 1280×640 social image, auto delete head branches.
  Next to "About", add description & tags; disable releases, packages, & environments.
  Add your open source license, GitHub uses the MIT license.
-->

# Employee-Management-System using C++

The project has multiple classes and sub-classes with some features within them. Basic operations users can perform via this program project which has such functions: adding new employee record, modifying employee record and deleting record, displaying one or all employee’s record. Besides these, employee management system also allows users to show the number of hours worked in the previous month.

</header>

<!--
  <<< Author notes: Step 1 >>>
  Choose 3-5 steps for your course.
  The first step is always the hardest, so pick something easy!
  Link to docs.github.com for further explanations.
  Encourage users to open new tabs for steps!
  TBD-step-1-notes.
-->

## The Project classes:
<p>1. UTILS<br />
- WAIT_FOR_ENTER<br />
- CENTER_TEXT<br />
<p>2. EMPLOYEE<br />
- ADD_EMPLOYEE<br />
- REMOVE_EMPLOYEE<br />
- DISPLAY_EMPLOYEE_INFO<br />
- DISPLAY_EMPLOYEE_LIST<br />
- EDIT_EMPLOYEE_DETAILS<br />
- HOURS_WORKED_IN_A_MONTH<br />
<p>3. MENU<br />
- START_PROGRAM<br />
- REGISTER_USER<br />
- LOGIN<br />
- DISPLAY_MENU<br />

## Project Operations:
<p>Addition of New Employee:<br />
This feature is under the public functions of class employee. The information handled in this feature are employee ID number, first name, second name, designation, age, address, phone number, years of experience, CTC.<br />
<p>Remove Employee Record:<br />
This method removes information about a given employee from the system when his ID number is provided.<br />
<p>Display Employee Info:<br />
Providing the employee ID number, users can access all the provided information related to a particular employee via this function. The employee record information displayed are the ones provided while adding a new employee record.<br />
<p>Display List of Employees:<br />
This feature displays the record of all employees added in file. The records are displayed in a tabular pattern containing information: employee ID number, first name, second name, designation, age, address, phone number, years of experience, CTC.<br />
<p>Edit Employee Details:<br />
This System in C++ asks for employee ID from the user for this function to work. Modifications that can be made are the employee ID number, first name, second name, designation, age, address, phone number, years of experience, CTC.<br />
<p>Hours Worked In A Month:<br />
This method generates the number of hours worked in the previous month for a given employee after entering his or her ID number. For each day of the week, a visualization appears on the screen in the form of vertical lines (their number indicates the number of hours worked on a given day). For Saturdays and Sundays, the number of hours was set to 0.<br />
<br />
Prepared by: Paweł Kierkosz 155995

<footer>

<!--
  <<< Author notes: Footer >>>
  Add a link to get support, GitHub status page, code of conduct, license link.
-->

---

Get help: [TBD-support](TBD-support-link) &bull; [Review the GitHub status page](https://www.githubstatus.com/)

&copy; 2023 TBD-copyright-holder &bull; [Code of Conduct](https://www.contributor-covenant.org/version/2/1/code_of_conduct/code_of_conduct.md) &bull; [MIT License](https://gh.io/mit)

</footer>
