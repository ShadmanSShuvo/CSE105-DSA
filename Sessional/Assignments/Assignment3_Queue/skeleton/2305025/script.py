import requests
import time

url = "https://camo.githubusercontent.com/5fe6e11ac6d577c1975effeb415b0fb52544486e5b57e0aad115666be5795bba/68747470733a2f2f6b6f6d617265762e636f6d2f67687076632f3f757365726e616d653d536861646d616e53536875766f26636f6c6f723d627269676874677265656e"
# "https://komarev.com/ghpvc/?username=ShadmanSShuvo&color=brightgreen"

# Number of times to hit the URL
hits = 1000  

# Delay between requests (in seconds) — avoid detection or rate-limiting
delay = .00001  

for i in range(hits):
    response = requests.get(url)
    print(f"Hit {i + 1}: Status code {response.status_code}")
    time.sleep(delay)