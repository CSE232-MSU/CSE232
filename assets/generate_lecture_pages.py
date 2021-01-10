import os
import json

os.chdir(os.path.dirname(os.path.abspath(__file__)))

data = json.load(open('lectures.json', 'r'))

for week_title, week_data in data.items():
    week_fname = week_title.strip().replace(' ', '').lower()

    fp_out = open('../lectures/{}.html'.format(week_fname), 'w+')

    print('---\ntitle: {}\n---'.format(week_title), file=fp_out)
    print('<h1>{}</h1>'.format(week_title), file=fp_out)

    for slides_title, slides_link in week_data['slides'].items():
        print('<p><a href="{}" target="_blank">Lecture Slides ({})</a></p>'.format(slides_link, slides_title), file=fp_out)
    
    if 'comments' in week_data:
        print('<p>{}</p>'.format(week_data['comments']), file=fp_out)

    for lecture_title, lecture_data in week_data['lectures'].items():
        print('<h3>{}</h3>'.format(lecture_title), file=fp_out)
        
        print('<div align="center">', file=fp_out)

        vref = lecture_data['video']
        v = vref[vref.find('v=') + 2:]
        print('<iframe class="border" width="640" height="360" src="https://www.youtube.com/embed/{}" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen=""></iframe>'.format(v), file=fp_out)

        if lecture_data['code']:
            print('<details class="details-reset details-overlay">', file=fp_out)
            print('<summary class="btn" aria-haspopup="true" style="width: 640px; text-align: center;">Example Code<div class="dropdown-caret"></div></summary>', file=fp_out)
            print('<div class="SelectMenu" style="left: calc(50vw - 320px);">', file=fp_out)
            print('<div class="SelectMenu-modal" style="width: 640px;">', file=fp_out)
            print('<div class="SelectMenu-list">', file=fp_out)
            for script_name in lecture_data['code']:
                if script_name not in os.listdir('../lectures/{}/'.format(week_fname)):
                    raise ValueError('{} not found in /lectures/{}/ (did you spell the file name correctly?)'.format(script_name, week_fname))
                script_path = week_fname + '/' + script_name
                print('<a class="SelectMenu-item" role="menuitem" href="{}" target="_blank">{}</a>'.format(script_path, script_name), file=fp_out)
            print('</div>', file=fp_out)
            print('</div>', file=fp_out)
            print('</div>', file=fp_out)
            print('</details>', file=fp_out)

        print('</div>', file=fp_out)
        
        if 'comments' in lecture_data:
            print('<p>{}</p>'.format(lecture_data['comments']), file=fp_out)

    fp_out.close()