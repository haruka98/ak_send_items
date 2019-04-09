# Item sender for Aura Kingdom

Small program to send items to players using the itemmall.

Generates a SQL file that needs to be executed in the FFAccount database.

Possible parameters:
- aura_kingdom_send_items.exe
- aura_kingdom_send_items.exe 123456
- aura_kingdom_send_items.exe 123456 testaccountname

"123456" is the request id for the first request (has to be unique).\
"testaccountname" is the name of the account that should get the items.

If the request id is missing the request will start at 10000.\
If you don't provide an account name you will be asked for the name each time you add a new item.

To close the program, just type "exit" in one of the fields.
