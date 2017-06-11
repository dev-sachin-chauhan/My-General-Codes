#!/usr/bin/env python
import time
from selenium import webdriver
from selenium.webdriver.common.keys import Keys

# create a new Chrome session
driver = webdriver.Chrome('/Users/sachin_chauhan/Downloads/chromedriver')
driver.implicitly_wait(30)
driver.maximize_window()

# navigate to the application home page
driver.get('http://courtnic.nic.in/supremecourt/caseno.asp')
time.sleep(1)
#driver.switch_to_frame(driver.find_element_by_name("sidebarmenu"));
#driver.find_elements_by_class_name('button')[1].click()
#time.sleep(1)
#driver.switch_to_default_content()
#driver.switch_to_frame(driver.find_element_by_name("content"));
#element = driver.find_element_by_name('caseTypeCode')
driver.find_element_by_xpath("//*[@id='seltype']/option[17]").click()
#element.select_by_value('CRIMINAL APPEAL').click()
element = driver.find_element_by_name('txtnumber')
element.send_keys('3709')

#driver.find_element_by_xpath("//select[@name='caseYear']/option[text()='1983']").click()
#element.select_by_value('1983').click()
#print(driver.page_source.encode("utf-8"))
#inputElement = driver.find_element_by_name("caseNumber")
#inputElement.send_keys('2413')
element.submit()
time.sleep(5)
#driver.quit()

#exit;

#import time
#from selenium import webdriver
#
#driver = webdriver.Chrome('/Users/sachin_chauhan/Downloads/chromedriver')  # Optional argument, if not specified will search path.
#driver.get('http://www.google.com/xhtml');
#time.sleep(5) # Let the user actually see something!
#search_box = driver.find_element_by_name('q')
#search_box.send_keys('ChromeDriver')
#search_box.submit()
#time.sleep(5) # Let the user actually see something!
#driver.quit()
