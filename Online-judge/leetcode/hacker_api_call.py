import requests
import json

def getUsernames(threshold):
    users = requests.get('https://jsonmock.hackerrank.com/api/article_users?page=1')
    users = (users.text)
    users = json.loads(users)
    total_page = users['total_pages'] 
    
    submission_users = []
    
    for page_number in range(1, total_page+1):
        users = requests.get('https://jsonmock.hackerrank.com/api/article_users?page='+str(page_number))
        users = (users.text)
        users = json.loads(users)
        users_data = users['data']
        for user in users_data:
            if user['submission_count'] > threshold:
                submission_users.append(user['username'])
    return submission_users
    
u = getUsernames(10)
print(u)
