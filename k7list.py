"build a header from list of data"
import sys, re
from os.path import getsize


args = [(re.sub('[^a-zA-Z0-9]', '_', arg), getsize(arg)) for arg in sys.argv[1:] ]


for arg,sz in args :
	print "extern const unsigned char %s[];"%arg
print "struct FileRecord {const uint8_t *data; const int size;};"

print "const struct FileRecord k7list[]= {"
for arg,sz in args :
	print '    {.data=%s, .size=%s},'%(arg,sz)
print "};"

print 'const char *k7list_str="'+'\\n'.join(arg.rsplit('_',1)[0].split('_',1)[1] for arg,sz in args)+'";'