from selenium import webdriver
from selenium.webdriver.chrome.options import Options
import sys

sys.stdin = open('idpwd.txt')

id = input()
pwd = input()
# selenium에서 사용할 웹 드라이버 절대 경로 정보
chromedriver = 'C:\Webdriver\chromedriver.exe'
# selenum의 webdriver에 앞서 설치한 chromedirver를 연동한다.
driver = webdriver.Chrome(chromedriver)

# driver로 특정 페이지를 크롤링한다.
driver.get('https://edu.ssafy.com')

driver.find_element_by_name('userId').send_keys(id)
driver.find_element_by_name('userPwd').send_keys(pwd)
driver.find_element_by_class_name('form-btn').click()


driver.set_window_size(1600, 800)

driver.find_element_by_xpath("//a[@href='/edu/lectureroom/openlearning/openLearningList.do']/span").click()

driver.find_element_by_id('searchContNm').send_keys('aps')

driver.find_element_by_xpath("//button[@onclick='fnSearch();']").click()

driver.find_elements_by_xpath("//*[contains(text(), 'A반_APS 응용')]")[0].click()

driver.find_element_by_xpath("//span[@class='file-name']").click()