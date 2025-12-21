You are managing a company database with two tables:

Master_Users

ID (primary key)

First_Name

Last_Name

Help_Requests

Request_ID (primary key)

User_ID (foreign key referencing Master_Users.ID)

Issue

Task:
Write an SQL query to find all users from Master_Users who have never raised a help request, i.e., whose ID does not appear as User_ID in the Help_Requests table.


To get users who never raised a help request:

sql
SELECT *
FROM Master_Users mu
WHERE mu.ID NOT IN (
    SELECT hr.User_ID
    FROM Help_Requests hr
);


or using joins:

sql
SELECT mu.*
FROM Master_Users AS mu
LEFT JOIN Help_Requests AS hr
  ON mu.ID = hr.User_ID
WHERE hr.User_ID IS NULL;