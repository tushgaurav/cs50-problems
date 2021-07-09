-- I did this to get the crime reports of the day of theft
SELECT description
FROM crime_scene_reports
WHERE year = 2020
AND month = 7
AND day = 28;

-- I then search the interviews about the crime
SELECT *
FROM interviews
WHERE transcript
LIKE "%courthouse%";

-- After going through the interviews, I gathered some infomation about ATM at
-- Fifer Street where the theif was seen withdrawing some money
SELECT *
FROM atm_transactions
WHERE month = 7
AND day = 28
AND atm_location = "Fifer Street";

-- I then looked the airports in Fiftyville
SELECT *
FROM airports
WHERE city = "Fiftyville";

-- I then looked for the flights from that airport on 29th July, which was told by
-- a witness in the interview
SELECT *
FROM flights
WHERE origin_airport_id = 8
AND year = 2020
AND day = 29;
AND month = 7;

-- As heard by a witness on phone that the thief would take the early flight which
-- I found out to be id 36, I looked for the passengers for that flight
SELECT *
FROM passengers
WHERE flight_id = 36;

-- I looked for each person on that flight by using their passport_number
SELECT *
FROM people
WHERE passport_number
IN (
SELECT passport_number
FROM passengers
WHERE flight_id = 36
);

-- In the interviews, one witness told that he saw the thief escaping from the scene
-- in under 10 minutes afer the robbery. So, I looked for the security logs to find
-- the license plate numbers which would match with the passengers of flight 36
SELECT *
FROM courthouse_security_logs
WHERE license_plate IN (
SELECT license_plate
FROM people
WHERE passport_number IN (
SELECT passport_number
FROM passengers
WHERE flight_id = 36
))
AND hour = 10
AND minute < 25;

-- Now I can see four suspect liscence plate numbers, I find name of each person from
-- their liscence plate numbers
SELECT *
FROM people
WHERE license_plate = "94KL13X";

SELECT *
FROM people
WHERE license_plate = "43228GD8";

SELECT *
FROM people
WHERE license_plate = "G412CB7";

SELECT *
FROM people
WHERE license_plate = "0NTHK55";

-- The four suspects are Ernest, Danielle, Roger and Evelyn. In the interview, the
-- thief was found talking on phone to his accomplice about the flight tickets at
-- the day of the thieft. Also the call lasted less than a minute. I searched who
-- talked on phone at that day for that duration.
SELECT *
FROM phone_calls
WHERE year = 2020
AND month = 7
AND day = 28
AND duration < 60;

-- I then matched the phone numbers to the suspects phone numbers and found a match
-- for Ernest. So, he is the thief. Now to find the accomplice, I found the name of
-- the person he talked on phone about the flight by looking the receiver phone no
SELECT *
FROM people
WHERE phone_number = "(375) 555-8161";

-- I found out that the accomplice was Berthold. Now, to found out that where the
-- thief went, I tracked the flight 36's destination
SELECT *
FROM flights
WHERE id = 36;

-- I found the destination airport's id to be 4. I then looked the name of the
-- airport and place.
SELECT *
FROM airports
WHERE id = 4;

-- I found the airport is Heathrow Airport which is in London. Hence, the case is
-- now SOLVED.