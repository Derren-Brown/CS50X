-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports
WHERE street = 'Humphrey Street'
AND month = 7
AND day = 28;
SELECT * FROM interviews
WHERE month = 7
AND day = 28;
--We know that the theft happened at 10:15 am. Ruth, Rugene and Raymond are the key people.
--The thief left the parking lot through a car at about 10:20 (10:15< <10:25).
--He took the earliest flight out of fiftyville on 7/29. The accomplice bought the ticket.
--Eugene recognized the thief. The thief withdrawed some money on Leggett Street before 10:15.
SELECT * FROM flights
WHERE month = 7
AND day = 29
AND origin_airport_id IN (
    SELECT origin_airport_id FROM flights
    JOIN airports ON flights.origin_airport_id = airports.id
    WHERE airports.city = 'Fiftyville')
ORDER BY hour ASC;
--The thief took the 36 flight from 8 to 4. The flight took off at 8:20.
SELECT people.id FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE month = 7
AND day = 28
AND duration < 60
INTERSECT
SELECT people.id FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE month = 7
AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw'
INTERSECT
SELECT people.id FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id = 36
INTERSECT
SELECT people.id FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute >= 15
AND bakery_security_logs.minute <= 20;
--The thief's id is 686048.
SELECT name FROM people
WHERE id = 686048;
--The thief is Bruce.
SELECT * FROM phone_calls
JOIN people ON people.phone_number = phone_calls.caller
WHERE people.name = 'Bruce'
AND month = 7
AND day = 28
AND duration < 60;
--The accomplice's phone number = (375) 555-8161
SELECT name FROM people
WHERE phone_number = '(375) 555-8161';
--The accomplice is Robin.
SELECT city FROM airports
WHERE id = 4;
--The thief escaped to New York City.