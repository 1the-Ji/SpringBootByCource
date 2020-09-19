package theji.algorithmproject.service;

import org.springframework.beans.factory.annotation.Autowired;
import theji.algorithmproject.Member.Member;
import theji.algorithmproject.repository.MemberRepository;

import javax.transaction.Transactional;
import java.util.List;
import java.util.Optional;

@Transactional
public class MemberService {

    private final MemberRepository memberRepository;

    @Autowired
    public MemberService(MemberRepository memberRepository) {
        this.memberRepository = memberRepository;
    }

    /**
     * 회원가입
     */
    public Long join(Member member) {
        long start = System.currentTimeMillis();
        try{
            validateionDuplicateMember(member);
            memberRepository.save(member);
            return member.getId();
        }finally {
            long finish = System.currentTimeMillis();
            long timeMs = finish - start;
            System.out.println("timeMs " + timeMs + "ms");
        }

    }
    /**
     * 전체 회원 조회
     */
    public List<Member> findMembers() {
        long start = System.currentTimeMillis();
        try{
            return memberRepository.findAll();
        }finally {
            long end = System.currentTimeMillis();
            long result = end - start;
            System.out.println("result =" + result + "ms");
        }
    }

    /**
     * 특정 회원 조회
     */
    public Optional<Member> findOne(Long memberId) {
        return memberRepository.findById(memberId);
    }

    private void validateionDuplicateMember(Member member) {
        memberRepository.findByName(member.getName()).ifPresent(m -> {
            throw new IllegalStateException("존재회원입니다.");
        });
    }
}

