import os 
from zipfile import ZipFile, ZIP_DEFLATED

os.chdir(os.path.dirname(os.path.realpath(__file__)))
os.chdir('../Lectures')

for week_folder in os.listdir():
    if '.' not in week_folder:

        week_num = week_folder[-2:]
        zip_file = ZipFile('../.assets/downloads/week{}.zip'.format(week_num), 'w')

        os.chdir(week_folder)
        
        for f in os.listdir():
            zip_file.write(f, compress_type=ZIP_DEFLATED)

        zip_file.close()
        os.chdir('..')
