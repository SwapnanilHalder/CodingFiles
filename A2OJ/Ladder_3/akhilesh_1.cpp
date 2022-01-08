n/k times hoga,

n-k , (n-k)*80%


select EMPLOYEE.name, EMPLOYEE.salary, DEPARTMENT.NAME, DEPARTMENT.LOCATION from Department DEPARTMENT left join Employee EMPLOYEE on EMPLOYEE.ID = DEPARTMENT.ID group by EMPLOYEE.ID order by SALARY desc, NAME 