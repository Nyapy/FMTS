from selenium import webdriver
from selenium.webdriver.chrome.options import Options
import sys
import time
import urllib.request
import os
sys.stdin = open('idpwd.txt')

site = input()
id = input()
pwd = input()
# selenium에서 사용할 웹 드라이버 절대 경로 정보
chromedriver = 'C:\Webdriver\chromedriver.exe'
# selenum의 webdriver에 앞서 설치한 chromedirver를 연동한다.
driver = webdriver.Chrome(chromedriver)

# driver로 특정 페이지를 크롤링한다.
driver.get(site)

driver.find_element_by_name('userId').send_keys(id)
driver.find_element_by_name('userPwd').send_keys(pwd)
driver.find_element_by_class_name('form-btn').click()


driver.set_window_size(1600, 800)

driver.find_element_by_xpath("//a[@href='/edu/lectureroom/openlearning/openLearningList.do']/span").click()

driver.find_element_by_id('searchContNm').send_keys('java')

driver.find_element_by_xpath("//button[@onclick='fnSearch();']").click()

driver.find_elements_by_xpath("//*[contains(text(), 'B반 Java(1)')]")[0].click()

driver.find_element_by_xpath("//span[@class='file-name']").click()

driver.switch_to.window(driver.window_handles[1])

driver.find_elements_by_xpath("//button[@title='단면/양면 보기 토글']")[0].click()

print(driver.find_elements_by_xpath("//button[@title='다음 페이지']")[0].get_attribute('disabled'))

cnt = 1
while 1:
    time.sleep(0.3)
    driver.save_screenshot('APS/C/'+str(cnt)+'.png')
    driver.find_elements_by_xpath("//button[@title='다음 페이지']")[0].click()
    cnt += 1
    if driver.find_elements_by_xpath("//button[@title='다음 페이지']")[0].get_attribute('disabled') == 'True':
        break
# driver.find_elements_by_xpath("//button[@title='마지막 페이지']")[0].click()
# print(driver.find_elements_by_xpath("//button[@title='다음 페이지']")[0].get_attribute('disabled'))

# url 가져오기 + find 함수 연습
# pre = driver.current_url
# find = pre.find('/index.html')
# url = pre[:find]

# src = driver.find_element_by_class_name("background").get_attribute('src')
# print(src)
## 다음페이지 넘기기
# for i in driver.find_elements_by_xpath("//button[@title='다음 페이지']"):
#     print(i)

cnt = 1
# url = driver.find_elements_by_class_name("background")[-1].get_attribute('src')
# print(url)
# urllib.request.urlretrieve(url, '123.jpg')
# os.system("curl " + url + " > test.jpg")

time.sleep(5)
driver.get_screenshot_as_file("hi.png")
# for i in driver.find_elements_by_class_name("background"):
#     time.sleep(2)
#     print(i.get_attribute('style'))
#     i.screenshot(str(cnt)+'.png')
#     cnt += 1


