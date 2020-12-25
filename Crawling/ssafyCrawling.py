from selenium import webdriver
from selenium.webdriver.chrome.options import Options

# selenium에서 사용할 웹 드라이버 절대 경로 정보
chromedriver = 'C:\Webdriver\chromedriver.exe'
# selenum의 webdriver에 앞서 설치한 chromedirver를 연동한다.
driver = webdriver.Chrome(chromedriver)

# driver로 특정 페이지를 크롤링한다.
driver.get('https://edu.ssafy.com')

driver.find_element_by_name('userId').send_keys('yveltal@naver.com')
driver.find_element_by_name('userPwd').send_keys('masa1234@')
driver.find_element_by_class_name('form-btn').click()


driver.set_window_size(1600, 800)
# print("+" * 100)
# print(driver.title)   # 크롤링한 페이지의 title 정보
# print(driver.current_url)  # 현재 크롤링된 페이지의 url
# print("바이크 브랜드 크롤링")
# print("-" * 100)
driver.find_element_by_xpath("//a[@href='/edu/lectureroom/openlearning/openLearningList.do']/span").click()

driver.find_element_by_id('searchContNm').send_keys('aps')

driver.find_element_by_xpath("//button[@onclick='fnSearch();']").click()