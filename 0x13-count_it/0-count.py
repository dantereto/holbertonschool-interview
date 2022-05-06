#!/usr/bin/python3
"""Comment"""
import requests


def count_words(subreddit, word_list, after=None, dic=None):
    """Count"""
    if dic is None:
        word_list = [word.lower() for word in word_list]
        dic = {key: 0 for key in word_list}

    hot = requests.get('https://api.reddit.com/r/{}/hot\
'.format(subreddit) + ('?after={}'.format(after) if after is not None else ''),
                       headers={'User-Agent': 'madmansilver'},
                       allow_redirects=False)

    if hot.status_code != 200:
        return

    hot = hot.json()

    if 'data' not in hot:
        print()
        return

    for post in hot.get('data').get('children'):
        for key in word_list:
            dic[key] += post.get('data').get('title').lower().split()\
                .count(key)

    after = hot.get('data').get('after')

    if after is None:
        for item in sorted(dic.items(), key=lambda i: (-i[1], i[0])):
            if (item[1] != 0):
                print('{}: {}'.format(item[0], item[1]))
        return

    count_words(subreddit, word_list, after, dic)
